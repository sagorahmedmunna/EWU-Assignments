#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    string num;
    string num2;
    string dep;
    string add;
    string subG;
    struct node *next;
};

struct node *head = NULL;

void welcome() {
    system("clear");
    cout << " ___________________________________\n";
    cout << "|                                   |\n";
    cout << "|    Welcome to PhoneBook library   |\n";
    cout << "|___________________________________|\n";
}

void print_done() {
    cout << "\n";
    cout << "             ________\n";
    cout << "            |        |\n";
    cout << "            |  Done! |\n";
    cout << "            |________|\n";
}

void print_CnotF() {
    cout << "\n\n";
    cout << "             _______________________\n";
    cout << "            |                       |\n";
    cout << "            |   Contact not found   |\n";
    cout << "            |_______________________|\n\n\n\n";
}

void print_TTBB() {
    cout << "\n\n";
    cout << "             _______________________\n";
    cout << "            |                       |\n";
    cout << "            |     TaTa Bye Bye...   |\n";
    cout << "            |_______________________|\n\n\n\n";
}

void file_print_list() {
    struct node *temp = head;
    ofstream file;
    file.open("Contacts.txt");
    while (temp != NULL) {
        file << temp->name << endl;
        file << temp->num << endl;
        file << temp->num2 << endl;
        file << temp->dep << endl;
        file << temp->add << endl;
        file << temp->subG << endl;
        temp = temp->next;
    }
    file.close();
}

void file_insert(string name, string num, string num2, string dep, string add, string subG) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->name = name;
    temp->num = num;
    temp->num2 = num2;
    temp->dep = dep;
    temp->add = add;
    temp->subG = subG;
    temp->next = NULL;
    
    if (head == NULL) head = temp;
    else {
        struct node *temp1 = head;
        while (temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
}

void sort_list() {
    struct node *i = head;
    if (i == NULL) return;
    while (i->next != NULL) {
        struct node *j = i->next;
        while (j != NULL) {
            if (i->name > j->name) {
                swap(i->name, j->name);
                swap(i->num, j->num);
                swap(i->num2, j->num2);
                swap(i->dep, j->dep);
                swap(i->add, j->add);
                swap(i->subG, j->subG);
            }
            j = j->next;
        }
        i = i->next;
    }
}

struct node* search_by_name(string name) {
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->name == name) break;
        curr = curr->next;
    }
    return curr;
}

struct node* search_by_number(string num) {
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->num == num) break;
        curr = curr->next;
    }
    return curr;
}

struct node* search_by_number2(string num2) {
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->num2 == num2) break;
        curr = curr->next;
    }
    return curr;
}

struct node* search_by_subG(string subG) {
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->subG ==subG) break;
        curr = curr->next;
    }
    return curr;
}

void insert() {
    system("clear");
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cout << endl;
    cout << "       Enter name:       ";
    string name; cin>>name;
    temp->name = name;
    cout << "       Enter number:     ";
    string num; cin>>num;
    temp->num = num;
    cout << "\n       Press s to skip...\n";
    cout << "       Enter 2nd number: ";
    string num2; cin>>num2;
    temp->num2 = num2;
    cout << "       Enter department: ";
    string dep; cin>>dep;
    temp->dep = dep;
    cout << "       Enter adress:     ";
    string add; cin>>add;
    temp->add = add;
    cout << "\n       Press s to skip...\n";
    cout << "       Enter sub-group:  ";
    string subG; cin>>subG;
    temp->subG = subG;
    temp->next = NULL;
    
    if (head == NULL) head = temp;
    else {
        struct node *curr = head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = temp;
    }

    print_done();
    sort_list();
    file_print_list();

    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

void edit() {
    system("clear");
    cout << "       Enter name or number: ";
    string name; cin>>name;
    struct node *n_name = search_by_name(name);
    struct node *n_num = search_by_number(name);
    struct node *n_num2 = search_by_number2(name);
    if (!n_name && !n_num && !n_num2) {print_CnotF(); return;}
    
    if (n_num) n_name = n_num;
    else if (n_num2) n_name = n_num2;
    cout << endl;
    cout << "       Enter new name:       ";
    cin>>name;
    n_name->name = name;
    cout << "       Enter new number:     ";
    string num; cin>>num;
    n_name->num = num;
    cout << "\n       Press s to skip...\n";
    cout << "       Enter new 2nd number: ";
    string num2; cin>>num2;
    n_name->num2 = num2;
    cout << "       Enter new department: ";
    string dep; cin>>dep;
    n_name->dep = dep;
    cout << "       Enter new adress:     ";
    string add; cin>>add;
    n_name->add = add;
    cout << "\n       Press s to skip...\n";
    cout << "       Enter new sub-group:  ";
    string subG; cin>>subG;
    n_name->subG = subG;

    print_done();
    sort_list();
    file_print_list();

    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

void search_contact() {
    system("clear");
    cout << "       Enter name or number or sub-group: ";
    string name; cin>>name;
    struct node *n_name = search_by_name(name);
    struct node *n_num = search_by_number(name);
    struct node *n_num2 = search_by_number2(name);
    struct node *n_subG = search_by_subG(name);

    if (n_subG) {
        system("clear");
        struct node* curr = head;
        while (curr != NULL) {
            if (curr->subG == name) {
                cout << "    ___________________________________\n";
                cout << "   |                                   |\n";
                cout << "   |      Name:       " << right << setw(11) << curr->name << "      |\n";
                cout << "   |      Number:     " << right << setw(11) << curr->num << "      |\n";
                if (curr->num2 != "s") 
                cout << "   |      2nd Number: " << right << setw(11) << curr->num2 << "      |\n";
                cout << "   |      Department: " << right << setw(11) << curr->dep << "      |\n";
                cout << "   |      Adress:     " << right << setw(11) << curr->add << "      |\n";
                if (curr->subG != "s") 
                cout << "   |      Sub-group:  " << right << setw(11) << curr->subG << "      |\n";
                cout << "   |___________________________________|" << endl;
            }
            curr = curr->next;
        }
        cout << "\n\n      press any key to continue...\n";
        string a; getline(cin,a); getline(cin,a); system("clear"); return;
    }

    if (!n_name && !n_num && !n_num2) {print_CnotF(); return;}
    
    system("clear");
    if (n_num) n_name = n_num;
    if (n_num2) n_name = n_num2;
    cout << "    ___________________________________\n";
    cout << "   |                                   |\n";
    cout << "   |      Name:       " << right << setw(11) << n_name->name << "      |\n";
    cout << "   |      Number:     " << right << setw(11) << n_name->num << "      |\n";
    if (n_name->num2 != "s") 
    cout << "   |      2nd Number: " << right << setw(11) << n_name->num2 << "      |\n";
    cout << "   |      Department: " << right << setw(11) << n_name->dep << "      |\n";
    cout << "   |      Adress:     " << right << setw(11) << n_name->add << "      |\n";
    if (n_name->subG != "s") 
    cout << "   |      Sub-group:  " << right << setw(11) << n_name->subG << "      |\n";
    cout << "   |___________________________________|" << endl;
    cout << endl;

    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

void delete_acc() {
    system("clear");
    cout << "       Enter name or number: ";
    string name; cin>>name;
    struct node *n_name = search_by_name(name);
    struct node *n_num = search_by_number(name);
    struct node *n_num2 = search_by_number2(name);
    if (!n_name && !n_num && !n_num2) {print_CnotF(); return;}

    cout << "\n       1. Delete only number\n";
    cout << "       2. Delete full contact\n";
    cout << "Enter your option: ";
    int del; cin>>del;

    if (del == 1) {
        cout << "\n       1. Delete number 1\n";
        cout << "       2. Delete number 2\n";
        cout << "Enter your option: ";
        int op; cin>>op;
        struct node *curr = head;

        if (op == 1) {
            while(curr != NULL){
                if (curr->name==name || curr->num==name || curr->num2==name) {
                    if (curr->num2 == "s") {
                        cout << "There is only one number left. You have to delete full contact.\n"; return;
                    }
                    curr->num = curr->num2;
                    curr->num2 = "s"; break;
                }
                curr = curr->next;
            }
        } else {
            while(curr != NULL){
                if (curr->name==name || curr->num==name || curr->num2==name) {
                    curr->num2 = "s"; break;
                }
                curr = curr->next;
            }
        }
    }
    else {
        if (head->name==name || head->num==name || head->num2==name) head = head->next;
        else {
            struct node *curr = head;
            struct node *prev;
            while(curr != NULL){
                if (curr->name==name || curr->num==name || curr->num2==name) break;
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        
    }

    print_done();
    file_print_list();
    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

void print_list() {
    system("clear");
    int c = 0;
    struct node* curr = head;
    if (!curr) {cout << "List is empty. TaTa Bye Bye...\n"; return;}

    while (curr != NULL) {
        cout << "    ___________________________________\n";
        cout << "   |                                   |\n";
        cout << "   |      Name:       " << right << setw(11) << curr->name << "      |\n";
        cout << "   |      Number:     " << right << setw(11) << curr->num << "      |\n";
        if (curr->num2 != "s") 
        cout << "   |      2nd Number: " << right << setw(11) << curr->num2 << "      |\n";
        cout << "   |      Department: " << right << setw(11) << curr->dep << "      |\n";
        cout << "   |      Adress:     " << right << setw(11) << curr->add << "      |\n";
        if (curr->subG != "s") 
        cout << "   |      Sub-group:  " << right << setw(11) << curr->subG << "      |\n";
        cout << "   |___________________________________|" << endl;
        c++;
        curr = curr->next;
    }
    cout << "\n         ___Total__" << c << "__contacts___\n";
    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

void about() {
    system("clear");
    cout << " ___________________________________\n";
    cout << "|    This is a application for      |\n";
    cout << "|    only East West University's    |\n";
    cout << "|    students. You can add contacts |\n";
    cout << "|    with some information. And     |\n";
    cout << "|    later you can modify by your   |\n";
    cout << "|    choice                         |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|  There are some features:         |\n";
    cout << "|     1. Add unlimited contact      |\n";
    cout << "|     2. Add upto two numbers       |\n";
    cout << "|     3. Edit whenever you want     |\n";
    cout << "|     4. Search by name or number   |\n";
    cout << "|        or sub-groups              |\n";
    cout << "|     5. Delete any contact or just |\n";
    cout << "|        only number                |\n";
    cout << "|     6. Contacts will save to the  |\n";
    cout << "|        memory and after reopening,|\n";
    cout << "|        the program will continue  |\n";
    cout << "|        from the savings data      |\n";
    cout << "|                                   |\n";
    cout << "|  There are some disadvantages:    |\n";
    cout << "|     1. Can not block              |\n";
    cout << "|     2. If more than one contact   |\n";
    cout << "|        have same name then first  |\n";
    cout << "|        contact will be deleted    |\n";
    cout << "|___________________________________|\n";
    cout << " ___________________________________\n";
    cout << "|                                   |\n";
    cout << "|   Developed by-                   |\n";
    cout << "|                                   |\n";
    cout << "|                                   |\n";
    cout << "|         Sagor Ahmed Munna         |\n";
    cout << "|          (2021-3-60-117)          |\n";
    cout << "|                                   |\n";
    cout << "|                 &                 |\n";
    cout << "|                                   |\n";
    cout << "|    Syeda Tasmiah Chowdhury Orpa   |\n";
    cout << "|          (2021-3-60-185)          |\n";
    cout << "|___________________________________|\n";
    cout << "\n\n      press any key to continue...\n";
    string a; getline(cin,a); getline(cin,a); system("clear");
}

int menu() {
    cout << " ___________________________________\n";
    cout << "|                                   |\n";
    cout << "|        1. Add a contact           |\n";
    cout << "|        2. Edit a contact          |\n";
    cout << "|        3. Search a contact        |\n";
    cout << "|        4. Delete a contact        |\n";
    cout << "|        5. Print contact list      |\n";
    cout << "|        6. About                   |\n";
    cout << "|        7. Exit                    |\n";
    cout << "|___________________________________|\n";
    cout << "Enter your option: ";
    int x; cin >> x;
    return x;
}

int main() {
    welcome();
    string name,num,num2,dep,add,subG,s;
    int c = 0;
    ifstream file("Contacts.txt");

    while (file >> s) {
        c++;
        if (c==1) name = s;
        if (c==2) num = s;
        if (c==3) num2 = s;
        if (c==4) dep = s;
        if (c==5) add = s;
        if (c==6) {
            subG = s; c=0;
            file_insert(name, num, num2, dep, add, subG);
        }
    }
    sort_list();
    file_print_list();

    while (true) {
        int x = menu();
        if (x == 1) insert();
        else if (x == 2) edit();
        else if (x == 3) search_contact();
        else if (x == 4) delete_acc();
        else if (x == 5) print_list();
        else if (x == 6) about();
        else if (x == 7) {system("clear");print_TTBB(); return 0;}
        else cout << "Try again...\n";
    }
    
    return 0;
}