// Section: 1
// Group: 2
// Tittle: Burger Buddies Problem

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>

int COOK_COUNT;
int CASHIER_COUNT;
int CUSTOMER_COUNT;
int RACK_CAPACITY;
int WAITING_TIME;

bool interrupt = false;

typedef struct{
    int id;
    sem_t *order;
    sem_t *burger;
} cashier_t;

typedef struct{
    int id;
    sem_t *init_done;
} simple_arg_t;

sem_t rack;
sem_t cook;
sem_t cashier;
sem_t cashier_awake;
sem_t customer;
sem_t customer_private_mutex;

cashier_t cashier_exchange;

int burger_count = 0;

void check_state() {
    if(burger_count < 0) {
        printf("ERROR --> Negative burger count!\n");
        exit(40);
    }

    if(burger_count > RACK_CAPACITY) {
        printf("ERROR --> Rack overfull!\n");
        exit(41);
    }

    printf("\t\t|               State is consistent.              |\n");
}

void *cook_func(void *args) {
    simple_arg_t *args_ptr = (simple_arg_t*) args;

    int cook_id = args_ptr->id;

    printf("COOK %d has been created.\n", cook_id + 1);
    sem_post(args_ptr->init_done);

    while(1) {
        sem_wait(&cook);
        if(interrupt) {
            break;
        }
        sleep(rand() % WAITING_TIME);

        sem_wait(&rack);
        check_state();
        burger_count++;
        check_state();
        sem_post(&rack);

        printf("COOK %d has placed a new burger in the rack.\n", cook_id + 1);

        sem_post(&cashier);
    }

    printf("\t\t|             COOK %d is done cooking.             |\n", cook_id + 1);
    return NULL;
}

void *cashier_func(void *args) {
    simple_arg_t *args_ptr = (simple_arg_t*) args;

    int cashier_id = args_ptr->id;

    sem_t order;
    sem_t burger;
    sem_init(&order, 0, 0);
    sem_init(&burger, 0, 0);

    printf("CASHIER %d has been created.\n", cashier_id + 1);
    sem_post(args_ptr->init_done);

    while(1) {
        sem_wait(&customer);

        if(interrupt) {
            break;
        }
        printf("CASHIER %d is Serving the customer.\n", cashier_id + 1);

        cashier_exchange.order = &order;
        cashier_exchange.burger = &burger;
        cashier_exchange.id = cashier_id;

        sem_post(&cashier_awake);
        sem_wait(&order);
        printf("CASHIER %d has got an order.\n", cashier_id + 1);

        printf("CASHIER %d is going to rack to get burger...\n", cashier_id + 1);

        sleep(rand() % WAITING_TIME);

        sem_wait(&cashier);
        sem_wait(&rack);
        check_state();
        burger_count--;
        check_state();
        sem_post(&rack);

        sem_post(&cook);

        printf("CASHIER %d got burger from rack, going back\n", cashier_id + 1);

        sleep(rand() % WAITING_TIME);

        sem_post(&burger);
        printf("CASHIER %d gave burger to customer.\n", cashier_id + 1);
    }

    sem_destroy(&order);
    sem_destroy(&burger);
    printf("\t\t|           CASHIER %d is done working.            |\n", cashier_id + 1);

    return NULL;
}

void *customer_func(void *args) {
    simple_arg_t *args_ptr = (simple_arg_t*) args;

    int customer_id = args_ptr->id;

    printf("CUSTOMER %d has been created.\n", customer_id + 1);
    sem_post(args_ptr->init_done);

    sleep(rand() % WAITING_TIME + 1);

    sem_wait(&customer_private_mutex);
    sem_post(&customer);
    sem_wait(&cashier_awake);


    sem_t *order = cashier_exchange.order;
    sem_t *burger = cashier_exchange.burger;
    int cashier_id = cashier_exchange.id;

    sem_post(&customer_private_mutex);

    printf("CUSTOMER %d approached to cashier no. %d.\n", customer_id + 1, cashier_id + 1);

    printf("CUSTOMER %d is placing an order to cashier no. %d.\n", customer_id + 1, cashier_id + 1);
    sleep(rand() % WAITING_TIME);

    sem_post(order);

    sem_wait(burger);

    printf("CUSTOMER %d got burger from cashier no. %d. Thank you!\n", customer_id + 1, cashier_id + 1);
    printf("\t\t|   CUSTOMER %d is done with his/her order.   |\n", customer_id + 1);

    return NULL;

}

int main(int argc, char **argv) {
    printf("\t\t\x1B[32m ______________________________\n");
    printf("\t\t|                              |\n");
    printf("\t\t|   Welcome to Burger Buddies  |\n");
    printf("\t\t|______________________________|\n\n");

    printf("\t\t Today's cook count: ");
    scanf("%d", &COOK_COUNT);
    printf("\t\t Today's cashier count: ");
    scanf("%d", &CASHIER_COUNT);
    printf("\t\t Today's customer count: ");
    scanf("%d", &CUSTOMER_COUNT);
    printf("\t\t Today's rack capacity: ");
    scanf("%d", &RACK_CAPACITY);
    printf("\t\t Today's waiting time: ");
    scanf("%d", &WAITING_TIME);
    printf("\n");

    srand(time(NULL));
    sem_init(&rack, 0, 1);
    sem_init(&cashier, 0, 1);
    sem_init(&cashier_awake, 0, 0);
    sem_init(&cook, 0, RACK_CAPACITY);
    sem_init(&customer, 0, 0);
    sem_init(&customer_private_mutex, 0, 1);

    simple_arg_t args;
    sem_t init_done;
    sem_init(&init_done, 0, 0);
    args.init_done = &init_done;

    pthread_t cooks[COOK_COUNT];
    for(int  i=0; i<COOK_COUNT; i++) {
        args.id = i;

        if(pthread_create(cooks+i, NULL, cook_func, (void*) &args)) {
            printf("ERROR: Unable to create cook thread.\n");
            exit(1);
        }

        sem_wait(&init_done);
    }

    pthread_t cashiers[CASHIER_COUNT];
    for(uint8_t i=0; i<CASHIER_COUNT; i++) {
        args.id = i;

        if(pthread_create(cashiers+i, NULL, cashier_func, (void*) &args)) {
            printf("ERROR: Unable to create cashier thread.\n");
            exit(2);
        }

        sem_wait(&init_done);
    }

    pthread_t customers[CUSTOMER_COUNT];
    for(int  i=0; i<CUSTOMER_COUNT; i++) {
        args.id = i;

        if(pthread_create(customers+i, NULL, customer_func, (void*) &args)) {
            printf("ERROR: Unable to create customer thread.\n");
            exit(3);
        }

        sem_wait(&init_done);
    }

    sem_destroy(&init_done);

    for(int  i=0; i<CUSTOMER_COUNT; i++) {
        if(pthread_join(customers[i], NULL)) {
            printf("ERROR: Unable to join cutomers %d\n", i + 1);
            exit(4);
        }
    }

    printf("\n\n\n");
    printf("\t\t\x1B[36m _________________________________________________\n");
    printf("\t\t|                                                 |\n");
    printf("\t\t|   All customers has been served successfully!   |\n");

    interrupt = true;

    for(int i=0; i<COOK_COUNT; i++) {
        sem_post(&cook);
    }

    for(int i=0; i<CASHIER_COUNT; i++) {
        sem_post(&customer);
    }
    printf("\t\t|   All threads has been terminated successfully! |\n");

    for(int i=0; i<COOK_COUNT; i++) {
        if(pthread_join(cooks[i], NULL)){
            printf("ERROR: Unable to join cooks %d\n", i + 1);
            exit(5);
        }
    }

    for(int  i=0; i<CASHIER_COUNT; i++) {
        if(pthread_join(cashiers[i], NULL)){
            printf("ERROR: Unable to join cashiers %d\n", i + 1);
            exit(6);
        }
    }
    check_state();
    printf("\t\t|   All threads has been terminated successfully! |\n");
    printf("\t\t|              in a consistent state.             |\n");
    printf("\t\t|_________________________________________________|\n\n");

    return 0;
}