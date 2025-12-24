#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <conio.h>

#include <windows.h>

void Option();
void HoldMenu();
void Option();
void Secret() {
    system("cls");
    system("color 04");
    int i, j, rows = 9;
    printf("\t\t\t\t\t");
    for (i = rows / 2; i <= rows; i += 2) {
        for (j = 1; j < rows - i; j += 2) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c", 3);
        }
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c", 3);
        }
        printf("\n\t\t\t\t\t");
        Sleep(50);
    }
    for (i = rows; i >= 1; i--) {
        if (i != rows)
            printf("\t\t\t\t\t");
        for (j = i; j < rows; j++) {
            printf(" ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) {
            printf("%c", 3);
        }
        printf("\n");
        Sleep(50);
    }
    printf("\n\n\tTeam members:");
    Sleep(50);
    printf("\n\t-------------");
    Sleep(50);
    printf("\n\n\tTaslima Akter Sathi\t\t   Sagor Ahmed \t\t  Ifrat Jahan Oishi\n");
    Sleep(50);
    printf("\t   2021-1-60-114   \t\t  2021-3-60-117\t\t    2021-3-60-229\n");
}
void About() {
    system("cls");
    printf("\t\tWelcome to Phonebook application.\n"
        "\t\tWe think you already know about this application\n"
        "\n\t\tFor secret code enter input '999' from main menu\n");
    printf("\n\t\tpress any key to continue !\n");
    getch();
    HoldMenu();
    Option();
}
void EditContact() {
    system("cls");
    system("color 06");
    menuUpper();
    printf("\t\t\t|    |         Edit Contact         |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\t\t\t                    ");
    printf("\n");
    char target[50];
    int flag = 0;
    printf("\t\t\t   Enter name or number: ");
    scanf("%s", target);
    while (1) {
        if ((target[0] == '0' && target[1] == '1') && (target[2] == '3' || target[2] == '5' || target[2] == '6' || target[2] == '7' || target[2] == '8' || target[2] == '9') &&
            (strlen(target) == 11)) {
            FILE * fp, * fp1;
            fp = fopen("phonebook.txt", "r");
            fp1 = fopen("temp.txt", "w");
            char name[50];
            char num[20];
            char mail[50];
            char address[50];
            char department[20];
            while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                if (strcmp(target, num) == 0) {
                    PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
                    printf("\t\t                  Contact has found\n");
                    printf("\n\n\t\t                 Enter new name: ");
                    scanf("%s", name);
                    while (1) {
                        int CountName = 0;
                        for (int i = 0;
                            (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == '_'; i++) {
                            CountName++;
                        }
                        if (CountName == strlen(name))
                            break;
                        else {
                            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                            printf("\t\t\t     Invalid name\n\n\t\t\t     Enter again: ");
                            scanf("%s", name);
                        }
                    }
                    printf("\n\t\t                 Enter new number: ");
                    scanf("%s", num);
                    while (1) {
                        if ((num[0] == '0' && num[1] == '1') && (num[2] == '3' || num[2] == '5' || num[2] == '6' || num[2] == '7' || num[2] == '8' || num[2] == '9') &&
                            (strlen(num) == 11))
                            break;
                        else {
                            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                            printf("\t\t\t     Invalid number\n\n\t\t\t     Enter again: ");
                            scanf("%s", num);
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 ");
                    printf("Enter new mail: ");
                    scanf("%s", mail);
                    if (strlen(mail) == 1 && (mail[0] == 'S' || mail[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountMail = 0;
                            for (int i = 0;
                                (mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= '0' && mail[i] <= '9') || mail[i] == '@' || mail[i] == '.' || mail[i] == '-' || mail[i] == '_'; i++) {
                                CountMail++;
                            }
                            int L = strlen(mail);
                            if ((CountMail == L) && (mail[L - 4] == '.') && ((mail[L - 3] == 'c' && mail[L - 2] == 'o' && mail[L - 1] == 'm') || (mail[L - 3] == 'e' && mail[L - 2] == 'd' && mail[L - 1] == 'u')))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Mail\n\n\t\t\t     Enter again: ");
                                scanf("%s", mail);
                            }
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 Enter new address: ");
                    scanf("%s", address);
                    if (strlen(address) == 1 && (address[0] == 'S' || address[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountAddress = 0;
                            for (int i = 0;
                                (address[i] >= 'A' && address[i] <= 'Z') || (address[i] >= 'a' && address[i] <= 'z') || address[i] == ',' || address[i] == '_' || (address[i] >= '0' && address[i] <= '9'); i++) {
                                CountAddress++;
                            }
                            if (CountAddress == strlen(address))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Address\n\n\t\t\t     Enter again: ");
                                scanf("%s", address);
                            }
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 Enter new department: ");
                    scanf("%s", department);
                    if (strlen(department) == 1 && (department[0] == 'S' || department[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountDepartment = 0;
                            for (int i = 0;
                                (department[i] >= 'A' && department[i] <= 'Z') || (department[i] >= 'a' && department[i] <= 'z') || department[i] == '_'; i++) {
                                CountDepartment++;
                            }
                            if (CountDepartment == strlen(department))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Department\n\n\t\t\t     Enter again: ");
                                scanf("%s", department);
                            }
                        }
                    }
                    fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                    flag++;
                } else {
                    fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                }
            }
            fclose(fp);
            fclose(fp1);
            fclose(fp);
            fclose(fp1);
            fp = fopen("phonebook.txt", "w");
            fp1 = fopen("temp.txt", "r");
            while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
            fclose(fp);
            fclose(fp1);
            remove("temp.txt");
        } else {
            FILE * fp, * fp1;
            fp = fopen("phonebook.txt", "r");
            fp1 = fopen("temp.txt", "w");
            char name[50];
            char num[20];
            char mail[50];
            char address[50];
            char department[20];
            while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                if (strcmp(target, name) == 0) {
                    PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
                    printf("\t\t                  Contact has found\n");
                    printf("\n\n\t\t                 Enter new name: ");
                    scanf("%s", name);
                    while (1) {
                        int CountName = 0;
                        for (int i = 0;
                            (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == '_'; i++) {
                            CountName++;
                        }
                        if (CountName == strlen(name))
                            break;
                        else {
                            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                            printf("\t\t\t     Invalid name\n\n\t\t\t     Enter again: ");
                            scanf("%s", name);
                        }
                    }
                    printf("\n\t\t                 Enter new number: ");
                    scanf("%s", num);
                    while (1) {
                        if ((num[0] == '0' && num[1] == '1') && (num[2] == '3' || num[2] == '5' || num[2] == '6' || num[2] == '7' || num[2] == '8' || num[2] == '9') &&
                            (strlen(num) == 11))
                            break;
                        else {
                            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                            printf("\t\t\t     Invalid number\n\n\t\t\t     Enter again: ");
                            scanf("%s", num);
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 Enter new mail: ");
                    scanf("%s", mail);
                    if (strlen(mail) == 1 && (mail[0] == 'S' || mail[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountMail = 0;
                            for (int i = 0;
                                (mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= '0' && mail[i] <= '9') || mail[i] == '@' || mail[i] == '.' || mail[i] == '-' || mail[i] == '_'; i++) {
                                CountMail++;
                            }
                            int L = strlen(mail);
                            if ((CountMail == L) && (mail[L - 4] == '.') && ((mail[L - 3] == 'c' && mail[L - 2] == 'o' && mail[L - 1] == 'm') || (mail[L - 3] == 'e' && mail[L - 2] == 'd' && mail[L - 1] == 'u')))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Mail\n\n\t\t\t     Enter again: ");
                                scanf("%s", mail);
                            }
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 Enter new address: ");
                    scanf("%s", address);
                    if (strlen(address) == 1 && (address[0] == 'S' || address[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountAddress = 0;
                            for (int i = 0;
                                (address[i] >= 'A' && address[i] <= 'Z') || (address[i] >= 'a' && address[i] <= 'z') || address[i] == ',' || address[i] == '_' || (address[i] >= '0' && address[i] <= '9'); i++) {
                                CountAddress++;
                            }
                            if (CountAddress == strlen(address))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Address\n\n\t\t\t     Enter again: ");
                                scanf("%s", address);
                            }
                        }
                    }
                    printf("Press 's' to skip this step!");
                    printf("\n\t\t                 Enter new department: ");
                    scanf("%s", department);
                    if (strlen(department) == 1 && (department[0] == 'S' || department[0] == 's'))
                        printf("Skipped this step!\n");
                    else {
                        while (1) {
                            int CountDepartment = 0;
                            for (int i = 0;
                                (department[i] >= 'A' && department[i] <= 'Z') || (department[i] >= 'a' && department[i] <= 'z') || department[i] == '_'; i++) {
                                CountDepartment++;
                            }
                            if (CountDepartment == strlen(department))
                                break;
                            else {
                                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                                printf("\t\t\t     Invalid Department\n\n\t\t\t     Enter again: ");
                                scanf("%s", department);
                            }
                        }
                    }
                    fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                    flag++;
                } else {
                    fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                }
            }
            fclose(fp);
            fclose(fp1);
            fclose(fp);
            fclose(fp1);
            fp = fopen("phonebook.txt", "w");
            fp1 = fopen("temp.txt", "r");
            while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
            fclose(fp);
            fclose(fp1);
            remove("temp.txt");
        }
        if (flag == 0) {
            PlaySound(TEXT("nothing_found.wav"), NULL, SND_ASYNC);
            printf("\n\t\t\t\t     Nothing Found\n");
            printf("\n\t\t\tPress 1 to search again or others to stop\n");
            int again;
            printf("\t\t\t                    ");
            scanf("%d", & again);
            if (again == 1) {
                EditContact();
            } else {
                Loading();
                Back();
                printf("\t\t\t                    ");
                getch();
                HoldMenu();
                Option();
            }
        } else {
            Loading();
            Back();
            printf("\t\t\t                    ");
            getch();
            HoldMenu();
            Option();
        }
    }
}
void menu1() {
    printf("\t\t\t                                            \n");
    printf("\t\t\t                                            \n");
    printf("\t\t\t   ________________________________________ \n");
    Sleep(35);
    printf("\t\t\t  /       _______________________         /|\n");
    Sleep(35);
    printf("\t\t\t /       (_______________________)       / |\n");
    Sleep(35);
    printf("\t\t\t/_______________________________________/  |\n");
    Sleep(35);
    printf("\t\t\t|                                       |  |\n");
    Sleep(35);
    printf("\t\t\t|    ________________________________   |  |\n");
    Sleep(35);
    printf("\t\t\t|    |------------------------------|   |  |\n");
    Sleep(35);
    printf("\t\t\t|    | Welcome to Digital Phonebook |   |  |\n");
    Sleep(35);
    printf("\t\t\t|    |------------------------------|   |  |\n");
    Sleep(35);
    printf("\t\t\t|                                       |  |\n");
    Sleep(35);
    printf("\t\t\t|     press the number to get access    |  |\n");
    Sleep(35);
    printf("\t\t\t|                                       |  |\n");
    Sleep(35);
    printf("\t\t\t|       __________________________      |  |\n");
    Sleep(35);
    printf("\t\t\t|      |                          |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  1. Add contact          |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  2. Edit contact         |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  3. Search contact       |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  4. Remove contact       |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  5. Block contact        |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  6. View Blocked contact |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  7. Unblock contact      |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  8. View All contact     |     |  |\n");
    Sleep(35);
    printf("\t\t\t|      |  9. Exit                 |     |  /\n");
    Sleep(35);
    printf("\t\t\t|      |  10.About Phonebook      |     |  /\n");
    Sleep(35);
    printf("\t\t\t|      |__________________________|     | /\n");
    Sleep(35);
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(35);
}
void menu_body() {
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    | Welcome to Digital Phonebook |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|     press the number to get access    |  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |  1. Add contact          |     |  |\n");
    printf("\t\t\t|      |  2. Edit contact         |     |  |\n");
    printf("\t\t\t|      |  3. Search contact       |     |  |\n");
    printf("\t\t\t|      |  4. Remove contact       |     |  |\n");
    printf("\t\t\t|      |  5. Block contact        |     |  |\n");
    printf("\t\t\t|      |  6. View Blocked contact |     |  |\n");
    printf("\t\t\t|      |  7. Unblock contact      |     |  |\n");
    printf("\t\t\t|      |  8. View All contact     |     |  |\n");
    printf("\t\t\t|      |  9. Exit                 |     |  /\n");
    printf("\t\t\t|      |  10.About Phonebook      |     |  /\n");
    Sleep(35);
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(1000);
}

void menu2() {
    system("cls");
    printf("\t\t\t                                            \n");
    printf("\t\t\t                                            \n");
    printf("\t\t\t   ______ ________________________ ________ \n");
    printf("\t\t\t  /      /_______________________/|       /|\n");
    printf("\t\t\t /       |_______________________|/      / |\n");
}

void menu3() {
    system("cls");
    printf("\t\t\t                                            \n");
    printf("\t\t\t          ________________________          \n");
    printf("\t\t\t   ______/_______________________/|________ \n");
    printf("\t\t\t  /      |                       ||       /|\n");
    printf("\t\t\t /       |_______________________|/      / |\n");
}

void menu4() {
    system("cls");
    printf("\t\t\t          ________________________          \n");
    printf("\t\t\t         /_______________________/|         \n");
    printf("\t\t\t   ______|                       ||________ \n");
    printf("\t\t\t  /      |                       ||       /|\n");
    printf("\t\t\t /       |_______________________|/      / |\n");
}
void menu5() {
    system("cls");
    time_t s, val = 1;
    struct tm * current_time;
    s = time(NULL);
    current_time = localtime( & s);
    printf("\t\t\t          ________________________          \n");
    printf("\t\t\t         /_______________________/|         \n");
    printf("\t\t\t   ______|                       ||________ \n");
    printf("\t\t\t  /      |        %02d:%02d:%02d       ||       /|\n", current_time -> tm_hour, current_time -> tm_min, current_time -> tm_sec);
    printf("\t\t\t /       |_______________________|/      / |\n");
}

void end1() {
    system("cls");
    menu5();
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |           Thank You          |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |    Stay                  |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |        Safe              |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |            Stay          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                 Happy    |     |  |\n");
    printf("\t\t\t|      |                          |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(2000);
}

void end2() {
    system("cls");
    menu4();
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |           Go                 |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |    Specially             |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(1000);
}

void end3() {
    system("cls");
    menu3();
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |           Goo                |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    PlaySound(TEXT("thanks.wav"), NULL, SND_ASYNC);
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |    Specially Thanks to   |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(1000);
}

void end4() {
    system("cls");
    menu2();
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |           Good               |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |    Specially Thanks to   |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |            Our           |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
    Sleep(1000);
}

void end5() {
    system("cls");
    printf("\t\t\t                                            \n");
    printf("\t\t\t                                            \n");
    printf("\t\t\t   ________________________________________ \n");
    printf("\t\t\t  /       _______________________         /|\n");
    printf("\t\t\t /       (_______________________)       / |\n");
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|    ________________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |           Good Bye           |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |    Specially Thanks to   |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |            Our           |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |     AHMED WASIF REZA     |     |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |            Sir           |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
}
void MainMenu() {
    menu1();
    menu2();
    menu_body();
    menu3();
    menu_body();
    menu4();
    menu_body();
    menu5();
    menu_body();
}
void Ending() {
    end1();
    end2();
    end3();
    end4();
    end5();
}
void menuUpper() {
    time_t s, val = 1;
    struct tm * current_time;
    s = time(NULL);
    current_time = localtime( & s);
    printf("\t\t\t          ________________________         \n");
    Sleep(35);
    printf("\t\t\t         /_______________________/|        \n");
    Sleep(35);
    printf("\t\t\t   ______|                       ||________\n");
    Sleep(35);
    printf("\t\t\t  /      |        %02d:%02d:%02d       ||       /|\n", current_time -> tm_hour, current_time -> tm_min, current_time -> tm_sec);
    Sleep(35);
    printf("\t\t\t /       |_______________________|/      / |\n");
    Sleep(35);
    printf("\t\t\t/_______________________________________/  |\n");
    Sleep(35);
    printf("\t\t\t|                                       |  |\n");
    Sleep(35);
    printf("\t\t\t|    ________________________________   |  |\n");
    Sleep(35);
    printf("\t\t\t|    |------------------------------|   |  |\n");
    Sleep(35);
}
void menuLower() {
    printf("\t\t\t|    |------------------------------|   |  /\n");
    Sleep(35);
    printf("\t\t\t|                                       | / \n");
    Sleep(35);
    printf("\t\t\t|_______________________________________|/  \n");
    Sleep(35);
}
void HoldMenu() {
    system("cls");
    time_t s, val = 1;
    struct tm * current_time;
    s = time(NULL);
    current_time = localtime( & s);
    printf("\t\t\t          ________________________         \n");
    printf("\t\t\t         /_______________________/|        \n");
    printf("\t\t\t   ______|                       ||________\n");
    printf("\t\t\t  /      |       %02d:%02d:%02d        ||       /|\n", current_time -> tm_hour, current_time -> tm_min, current_time -> tm_sec);
    printf("\t\t\t /       |_______________________|/      / |\n");
    printf("\t\t\t/_______________________________________/  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|     _______________________________   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|    |       Digital Phonebook      |   |  |\n");
    printf("\t\t\t|    |------------------------------|   |  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|     press the number to get access    |  |\n");
    printf("\t\t\t|                                       |  |\n");
    printf("\t\t\t|       __________________________      |  |\n");
    printf("\t\t\t|      |                          |     |  |\n");
    printf("\t\t\t|      |  1. Add contact          |     |  |\n");
    printf("\t\t\t|      |  2. Edit contact         |     |  |\n");
    printf("\t\t\t|      |  3. Search contact       |     |  |\n");
    printf("\t\t\t|      |  4. Remove contact       |     |  |\n");
    printf("\t\t\t|      |  5. Block contact        |     |  |\n");
    printf("\t\t\t|      |  6. View Blocked contact |     |  |\n");
    printf("\t\t\t|      |  7. Unblock contact      |     |  |\n");
    printf("\t\t\t|      |  8. View All contact     |     |  |\n");
    printf("\t\t\t|      |  9. Exit                 |     |  /\n");
    printf("\t\t\t|      |  10.About Phonebook      |     |  /\n");
    printf("\t\t\t|      |__________________________|     | /\n");
    printf("\t\t\t|_______________________________________|/\n");
}
void Loading() {
    printf("\n\t\t\t       Loading .");
    Sleep(500);
    printf(" .");
    Sleep(500);
    printf(" .");
    Sleep(500);
    printf(" .");
    Sleep(500);
    printf(" .");
    Sleep(500);
    PlaySound(TEXT("updatesuccessfully.wav"), NULL, SND_ASYNC);
    printf("\n\n\t\t\t       Update Successfully");
    Sleep(2500);
}
void Back() {
    printf("\n\t\t\t _______________________________________\n");
    Sleep(20);
    printf("\t\t\t|    |                              |   |\n");
    Sleep(20);
    printf("\t\t\t|    |   Press any key to go back   |   |\n");
    Sleep(20);
    printf("\t\t\t|    |      to the main menu        |   |\n");
    Sleep(20);
    printf("\t\t\t|____|______________________________|___|\n");
    Sleep(20);
}
void AddContact() {
    system("color 0E");
    FILE * fp;
    fp = fopen("phonebook.txt", "a+");
    system("cls");
    menuUpper();
    printf("\t\t\t|    |          Add Contact         |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n\t\t                 ");
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    while (1) {
        int CountName = 0;
        for (int i = 0;
            (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == '_'; i++) {
            CountName++;
        }
        if (CountName == strlen(name))
            break;
        else {
            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
            printf("\t\t\t     Invalid name\n\n\t\t\t     Enter again: ");
            scanf("%s", name);
        }
    }
    char num[20];
    printf("\n\t\t                 ");
    printf("Enter Number: ");
    scanf("%s", num);
    while (1) {
        if ((num[0] == '0' && num[1] == '1') && (num[2] == '3' || num[2] == '5' || num[2] == '6' || num[2] == '7' || num[2] == '8' || num[2] == '9') &&
            (strlen(num) == 11))
            break;
        else {
            PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
            printf("\t\t\t     Invalid number\n\n\t\t\t     Enter again: ");
            scanf("%s", num);
        }
    }
    char mail[50];
    printf("Press 's' to skip this step!");
    printf("\n\t\t                 ");
    printf("Enter mail: ");
    scanf("%s", mail);
    if (strlen(mail) == 1 && (mail[0] == 'S' || mail[0] == 's'))
        printf("Skipped this step!\n");
    else {
        while (1) {
            int CountMail = 0;
            for (int i = 0;
                (mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= '0' && mail[i] <= '9') || mail[i] == '@' || mail[i] == '.' || mail[i] == '-' || mail[i] == '_'; i++) {
                CountMail++;
            }
            int L = strlen(mail);
            if ((CountMail == L) && (mail[L - 4] == '.') && ((mail[L - 3] == 'c' && mail[L - 2] == 'o' && mail[L - 1] == 'm') || (mail[L - 3] == 'e' && mail[L - 2] == 'd' && mail[L - 1] == 'u')))
                break;
            else {
                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                printf("\t\t\t     Invalid Mail\n\n\t\t\t     Enter again: ");
                scanf("%s", mail);
            }
        }
    }
    char address[50];
    printf("Press 's' to skip this step!");
    printf("\n\t\t                 ");
    printf("Enter address: ");
    scanf("%s", address);
    if (strlen(address) == 1 && (address[0] == 'S' || address[0] == 's'))
        printf("Skipped this step!\n");
    else {
        while (1) {
            int CountAddress = 0;
            for (int i = 0;
                (address[i] >= 'A' && address[i] <= 'Z') || (address[i] >= 'a' && address[i] <= 'z') || address[i] == ',' || address[i] == '_' || (address[i] >= '0' && address[i] <= '9'); i++) {
                CountAddress++;
            }
            if (CountAddress == strlen(address))
                break;
            else {
                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                printf("\t\t\t     Invalid Address\n\n\t\t\t     Enter again: ");
                scanf("%s", address);
            }
        }
    }
    char department[20];
    printf("Press 's' to skip this step!");
    printf("\n\t\t                 ");
    printf("Enter department: ");
    scanf("%s", department);
    if (strlen(department) == 1 && (department[0] == 'S' || department[0] == 's'))
        printf("Skipped this step!\n");
    else {
        while (1) {
            int CountDepartment = 0;
            for (int i = 0;
                (department[i] >= 'A' && department[i] <= 'Z') || (department[i] >= 'a' && department[i] <= 'z') || department[i] == '_'; i++) {
                CountDepartment++;
            }
            if (CountDepartment == strlen(department))
                break;
            else {
                PlaySound(TEXT("error.wav"), NULL, SND_ASYNC);
                printf("\t\t\t     Invalid Department\n\n\t\t\t     Enter again: ");
                scanf("%s", department);
            }
        }
    }
    fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
    fclose(fp);
    Loading();
    HoldMenu();
    Option();
}
void SearchContact() {
    system("cls");
    system("color 05");
    menuUpper();
    printf("\t\t\t|    |        Search Contact        |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n");
    char target[50];
    int flag = 0;
    printf("\t\t\t     press s to skip !\n");
    printf("\t\t\t   Enter name or number: ");
    scanf("%s", target);
    if (strlen(target) == 1 && (target[0] == 'S' || target[0] == 's')) {
        Loading();
        Back();
        printf("\t\t\t                    ");
        getch();
        HoldMenu();
        Option();
    } else {
        while (1) {
            if ((target[0] == '0' && target[1] == '1') && (target[2] == '3' || target[2] == '5' || target[2] == '6' || target[2] == '7' || target[2] == '8' || target[2] == '9') &&
                (strlen(target) == 11)) {
                FILE * fp;
                fp = fopen("phonebook.txt", "r");
                char name[50];
                char num[20];
                char mail[50];
                char address[50];
                char department[20];
                while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                    if (strcmp(target, num) == 0) {
                        PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
                        printf("\n\t\t\t\t     Contact has found\n\n");
                        printf("\n\t\t\t|  Name      : %s\n", name);
                        Sleep(20);
                        printf("\t\t\t|  Number    : %s\n", num);
                        Sleep(20);
                        printf("\t\t\t|  Mail      : %s\n", mail);
                        Sleep(20);
                        printf("\t\t\t|  Address   : %s\n", address);
                        Sleep(20);
                        printf("\t\t\t|  Department: %s\n\n", department);
                        Sleep(20);
                        flag++;
                        break;
                    }
                }
                fclose(fp);
            } else {
                FILE * fp;
                fp = fopen("phonebook.txt", "r");
                char name[50];
                char num[20];
                char mail[50];
                char address[50];
                char department[20];
                while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
                    if (strcmp(target, name) == 0) {
                        PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
                        printf("\n\t\t\t\t     Contact has found\n\n");
                        printf("\n\t\t\t|  Name      : %s\n", name);
                        Sleep(20);
                        printf("\t\t\t|  Number    : %s\n", num);
                        Sleep(20);
                        printf("\t\t\t|  Mail      : %s\n", mail);
                        Sleep(20);
                        printf("\t\t\t|  Address   : %s\n", address);
                        Sleep(20);
                        printf("\t\t\t|  Department: %s\n\n", department);
                        Sleep(20);
                        flag++;
                        break;
                    }
                }
                fclose(fp);
            }
            if (flag == 0) {
                PlaySound(TEXT("nothing_found.wav"), NULL, SND_ASYNC);
                printf("\n\t\t\t\t     Nothing Found\n");
                printf("\n\t\t\tPress 1 to search again or others to stop\n");
                int again;
                printf("\t\t\t                    ");
                scanf("%d", & again);
                if (again == 1) {
                    SearchContact();
                } else {
                    Loading();
                    Back();
                    printf("\t\t\t                    ");
                    getch();
                    HoldMenu();
                    Option();
                }
            } else {
                Back();
                printf("\t\t\t                    ");
                getch();
                Loading();
                HoldMenu();
                Option();
                break;
            }
        }
    }
}
void RemoveContact() {
    system("cls");
    system("color 0C");
    menuUpper();
    printf("\t\t\t|    |        Remove Contact        |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n");
    char target[50];
    int flag = 0;
    printf("\n\t\t\t   Enter name or number: ");
    scanf("%s", target);
    if ((target[0] == '0' && target[1] == '1') && (target[2] == '3' || target[2] == '5' || target[2] == '6' || target[2] == '7' || target[2] == '8' || target[2] == '9') &&
        (strlen(target) == 11)) {
        FILE * fp, * fp1;
        fp = fopen("phonebook.txt", "r");
        fp1 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(num, target) == 0) {
                flag++;
                continue;
            }
            fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("phonebook.txt", "w");
        fp1 = fopen("temp.txt", "r");
        while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp1);
        remove("temp.txt");
        flag++;
    } else {
        FILE * fp, * fp1;
        fp = fopen("phonebook.txt", "r");
        fp1 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(name, target) == 0) {
                flag++;
                continue;
            }
            fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("phonebook.txt", "w");
        fp1 = fopen("temp.txt", "r");
        while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp1);
        remove("temp.txt");
    }
    if (flag == 0) {
        PlaySound(TEXT("nothing_found.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\t\t     Nothing Found\n");
        printf("\n\t\t\tPress 1 to search again or others to stop\n");
        int again;
        printf("\t\t\t                    ");
        scanf("%d", & again);
        if (again == 1) {
            RemoveContact();
        } else {
            Loading();
            Back();
            printf("\t\t\t                    ");
            getch();
            HoldMenu();
            Option();
        }
    } else {
        PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\t\t   Contact has found\n");
        Loading();
        Back();
        printf("\t\t\t                    ");
        getch();
        HoldMenu();
        Option();
    }
}
void BlockContact() {
    system("cls");
    system("color 04");
    menuUpper();
    printf("\t\t\t|    |         Block Contact        |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n");
    char target[50];
    int flag = 0;
    printf("\t\t\t   Enter name or number: ");
    scanf("%s", target);
    if ((target[0] == '0' && target[1] == '1') && (target[2] == '3' || target[2] == '5' || target[2] == '6' || target[2] == '7' || target[2] == '8' || target[2] == '9') &&
        (strlen(target) == 11)) {
        FILE * fp, * fp1, * fp2;
        fp = fopen("phonebook.txt", "r");
        fp1 = fopen("phonebook_block.txt", "a+");
        fp2 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(num, target) == 0) {
                fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                flag++;
            } else {
                fprintf(fp2, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
        }
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fp = fopen("phonebook.txt", "w");
        fp2 = fopen("temp.txt", "r");
        while (fscanf(fp2, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp2);
        remove("temp.txt");
    } else {
        FILE * fp, * fp1, * fp2;
        fp = fopen("phonebook.txt", "r");
        fp1 = fopen("phonebook_block.txt", "a+");
        fp2 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(name, target) == 0) {
                fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
                flag++;
            } else {
                fprintf(fp2, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
        }
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fp = fopen("phonebook.txt", "w");
        fp2 = fopen("temp.txt", "r");
        while (fscanf(fp2, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp);
        fclose(fp2);
        remove("temp.txt");
    }
    if (flag == 0) {
        PlaySound(TEXT("nothing_found.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\t\t     Nothing Found\n");
        printf("\n\t\t\tPress 1 to search again or others to stop\n");
        int again;
        printf("\t\t\t                    ");
        scanf("%d", & again);
        if (again == 1) {
            BlockContact();
        } else {
            Loading();
            Back();
            printf("\t\t\t                    ");
            getch();
            HoldMenu();
            Option();
        }
    } else {
        PlaySound(TEXT("block.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\t\t   Contact has found\n");
        printf("\n\t\t\t       Loading .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf("\n\n\t\t\t       Update Successfully");
        Sleep(2500);
        Back();
        printf("\t\t\t                    ");
        getch();
        HoldMenu();
        Option();
    }
}
void ViewBlockedContact() {
    system("cls");
    system("color 0D");
    menuUpper();
    printf("\t\t\t|    |     View Blocked Contact     |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n\n");
    FILE * fp;
    fp = fopen("phonebook_block.txt", "r");
    char name[50];
    char num[20];
    char mail[50];
    char address[50];
    char department[20];
    while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
        printf("\t\t\t|  Name      : %s\n", name);
        Sleep(20);
        printf("\t\t\t|  Number    : %s\n", num);
        Sleep(20);
        printf("\t\t\t|  Mail      : %s\n", mail);
        Sleep(20);
        printf("\t\t\t|  Address   : %s\n", address);
        Sleep(20);
        printf("\t\t\t|  Department: %s\n\n", department);
        Sleep(20);
    }
    fclose(fp);
    Back();
    printf("\t\t\t                    ");
    getch();
    Loading();
    HoldMenu();
    Option();
}
void UnblockContact() {
    system("color 09");
    system("cls");
    menuUpper();
    printf("\t\t\t|    |        Unblock Contact       |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n");
    char target[50];
    int flag = 0;
    printf("\t\t\t   Enter name or number: ");
    scanf("%s", target);
    if ((target[0] == '0' && target[1] == '1') && (target[2] == '3' || target[2] == '5' || target[2] == '6' || target[2] == '7' || target[2] == '8' || target[2] == '9') &&
        (strlen(target) == 11)) {
        FILE * fp, * fp1, * fp2;
        fp = fopen("phonebook.txt", "a");
        fp1 = fopen("phonebook_block.txt", "r");
        fp2 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(num, target) == 0) {
                fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
                flag++;
            } else {
                fprintf(fp2, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
        }
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fp1 = fopen("phonebook_block.txt", "w");
        fp2 = fopen("temp.txt", "r");
        while (fscanf(fp2, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp1);
        fclose(fp2);
        remove("temp.txt");
    } else {
        FILE * fp, * fp1, * fp2;
        fp = fopen("phonebook.txt", "a");
        fp1 = fopen("phonebook_block.txt", "r");
        fp2 = fopen("temp.txt", "w");
        char name[50];
        char num[20];
        char mail[50];
        char address[50];
        char department[20];
        while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(name, target) == 0) {
                fprintf(fp, "%s %s %s %s %s\n", name, num, mail, address, department);
                flag++;
            } else {
                fprintf(fp2, "%s %s %s %s %s\n", name, num, mail, address, department);
            }
        }
        fclose(fp);
        fclose(fp1);
        fclose(fp2);
        fp1 = fopen("phonebook_block.txt", "w");
        fp2 = fopen("temp.txt", "r");
        while (fscanf(fp2, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            fprintf(fp1, "%s %s %s %s %s\n", name, num, mail, address, department);
        }
        fclose(fp1);
        fclose(fp2);
        remove("temp.txt");
    }
    if (flag == 0) {

        printf("\n\t\t\t\t     Nothing Found\n");
        PlaySound(TEXT("nothing_found.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\tPress 1 to search again or others to stop\n");
        int again;
        printf("\t\t\t                    ");
        scanf("%d", & again);
        if (again == 1) {
            UnblockContact();
        } else {
            Loading();
            Back();
            printf("\t\t\t                    ");
            getch();
            HoldMenu();
            Option();
        }
    } else {
        PlaySound(TEXT("contact_found.wav"), NULL, SND_ASYNC);
        printf("\n\t\t\t\t   Contact has found\n");
        Sleep(25);

        Loading();
        Back();
        printf("\t\t\t                    ");
        getch();
        HoldMenu();
        Option();
    }
}
void ViewAllContact() {
    system("cls");
    system("color 02");
    menuUpper();
    printf("\t\t\t|    |          All Contact         |   |  |\n");
    Sleep(35);
    menuLower();
    printf("\n");
    FILE * fp, * fp1, * fp2;
    fp = fopen("phonebook.txt", "r");
    char name[50];
    char num[20];
    char mail[50];
    char address[50];
    char department[20];
    char str[100][100];
    int c = 0;
    while (fscanf(fp, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
        strcpy(str[c], name);
        c++;
    }
    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                char hold[100];
                strcpy(hold, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], hold);
            }
        }
    }
    fp1 = fopen("phonebook.txt", "r");
    int i = 0;
    while (fscanf(fp1, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {

        fp2 = fopen("phonebook.txt", "r");
        while (fscanf(fp2, "%s %s %s %s %s", name, num, mail, address, department) != EOF) {
            if (strcmp(str[i], name) == 0) {
                printf("\t\t\t Contact no: %d\n", i + 1);
                printf("\t\t\t|  Name      : %s\n", name);
                Sleep(20);
                printf("\t\t\t|  Number    : %s\n", num);
                Sleep(20);
                printf("\t\t\t|  Mail      : %s\n", mail);
                Sleep(20);
                printf("\t\t\t|  Address   : %s\n", address);
                Sleep(20);
                printf("\t\t\t|  Department: %s\n\n", department);
                Sleep(20);
                i++;
                break;
            }
        }
    }
    fclose(fp);
    printf("\n\t\t\t  Total contact= %d", i);
    Back();
    printf("\t\t\t                    ");
    getch();
    Loading();
    HoldMenu();
    Option();
}
void Option() {
    int select;
    printf("\t\t\t                    ");
    scanf("%d", & select);
    switch (select) {
    case 1:
        AddContact();
        break;
    case 2:
        EditContact();
        break;
    case 3:
        SearchContact();
        break;
    case 4:
        RemoveContact();
        break;
    case 5:
        BlockContact();
        break;
    case 6:
        ViewBlockedContact();
        break;
    case 7:
        UnblockContact();
        break;
    case 8:
        ViewAllContact();
        break;
    case 9:
        HoldMenu();
        printf("\n\t\t\t     Loading .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf(" .");
        Sleep(500);
        printf("\n\n\t\t\t     Update Successfully");
        Sleep(2500);
        PlaySound(TEXT("exit.wav"), NULL, SND_ASYNC);
        Ending();
        Sleep(2000);
        exit(0);
    case 10:
        About();
        break;
    case 999:
        Secret();
        break;
    default:
        HoldMenu();
        Option();
    }
}
int main() {
    system("color 0A");
    PlaySound(TEXT("welcome.wav"), NULL, SND_ASYNC);
    MainMenu();
    Option();
}