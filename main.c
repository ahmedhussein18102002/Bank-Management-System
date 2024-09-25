#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100


/* Function Declaration */
void menu();
void newAccount();
void viewList();
void edit();
void transact(float money[]);
void erase();
void see();
void search();
void sort();
/* --------------- */

/* Arrays used to store clients informations */
char names[MAX][10] = {
    "Islam",
    "Ahmed",
    "Hussein",
    "Antonius",
    "Magdy"
};
char date_birth[MAX][12] = {
    "12/4/2002",
    "2/7/2006",
    "12/1/2000",
    "12/8/1995",
    "12/10/2010"
};
char national[MAX][15] = {
    "12345678912340",
    "98765432101598",
    "48675910325956",
    "49153705097216",
    "15790310006214"
};
char address[MAX][20] = {
    "3786 Brentwood",
    "974 Illinois",
    "2273 Cottrill",
    "31 Grasselli",
    "2382 Ashford"
};
char phone[MAX][15] = {
    "703-636-2355",
    "716-807-9387",
    "207-407-3468",
    "209-684-4146",
    "218-465-6280"
};
unsigned short int depositType[MAX] = { 1 , 3 , 2 , 2 , 1};
float money[MAX] = {
    1000,
    1500,
    500,
    250,
    1250
};
/* --------------- */

/* Global Variables used */
int number_of_accounts = 5;
/* --------------- */


int main()
{
    puts("Welcome to the Bank Management System");
    int password , answer;
    do {
        printf("Please enter numerical password :");
        if (scanf("%d" , &password) == 0) { // checking if the user wrote integar or not
            puts("We tracked an extreme error so we closed the program");
            return 0; // closing program to prevent errors
        }
        if (password == 1234) {
            break; // break the loop and continue the program if the password is right
        } else {
            printf("Wrong password if you wanna try again press 1 or 2 for exit the program:");
            scanf("%d" , &answer); // scan the user choice
        }
        if (answer == 1) {
            continue; // let the user make another try and renter password
        } else if (answer == 2) {
            return 0; // exiting the program
        } else {
            printf("Invalid answer\n");
            continue; // make another try if the user wrote wrong
        }
    } while (1);
    system("cls"); // clearing the console
    puts("Welcome to our system");
    menu();




    return 0;
}
void menu () {
    system("cls");
    printf("please enter the value which determines your service as \n%s \n%s \n%s \n%s \n%s \n%s \n%s \n%s \n%s \n",
          "1- for new account",
          "2- view list",
          "3- edit",
          "4- transact",
          "5- erase",
          "6- see",
          "7- search",
          "8- sort",
          "other number will restart the program"
         );
    int menu_answer;
    scanf("%i",&menu_answer);
    system("cls");
    switch (menu_answer) {
    case 1:
        newAccount();
        break;
    case 2:
        viewList();
        break;
    case 3:
        edit();
        break;
    case 4:
        transact(money);
        break;
    case 5:
        erase();
        break;
    case 6:
        see();
        break;
    case 7:
        search();
        break;
    case 8:
        sort();
        break;
    default :
        main();
        break;
    }
}
void newAccount() {
    for (number_of_accounts = 1 ; names[number_of_accounts - 1][10] != '\0' ; number_of_accounts++);
    printf("Please, enter your name :");
    scanf("%s" , names[number_of_accounts]);
    printf("Please, enter your birth date :");
    scanf("%s" , date_birth[number_of_accounts]);
    printf("Please, enter your national ID :");
    scanf("%s" , national[number_of_accounts]);
    printf("Please, enter your address :");
    scanf("%s" , address[number_of_accounts]);
    printf("Please, enter your phone :");
    scanf("%s" , phone[number_of_accounts]);
    printf("Please, Enter The Type of you personal account money transact where \n1- saving \n2- current \n3- investment \n");
    scanf("%hu" , &depositType[number_of_accounts]);
    printf("Enter the value of the money you will deposite :");
    scanf("%f" , &money[number_of_accounts]);
    number_of_accounts++;
    puts("A new Client is succesfully added");
    system("pause");
    system("cls");
    menu();
}
void viewList() {
    int client_counter;
    printf("     Name:     Data Birth      National ID           Address             Phone\n");
    for (client_counter = 0 ; client_counter < number_of_accounts ; client_counter++) {
        printf("%10s   %12s   %14s   %15s   %15s\n" ,
                names[client_counter],
                date_birth[client_counter],
                national[client_counter],
                address[client_counter],
                phone[client_counter]);
    }
    puts("For going back to menu");
    system("pause");
    system("cls");
    menu();

}
void edit() {
    printf("Enter The Account Number of the client you want to edit :");
    unsigned short int acc_num , acc_info;
    scanf("%hu" , &acc_num);
    printf("Enter the information you want to edit where\n %s\n %s\n\n" ,
           "1- Account address",
           "2- Account phone number"
           );
    scanf("%hu" , &acc_info);
    switch (acc_info) {
    case 1:
        printf("old address is : %s\n" , address[acc_num - 1]);
        printf("Enter the new address:");
        scanf("%s" , address[acc_num - 1]);
        break;
    case 2:
        printf("old Phone number is : %s\n" , phone[acc_num - 1]);
        printf("Enter the new phone number:");
        scanf("%s" , phone[acc_num - 1]);
        break;
    default:
        puts("invalid choice");
        break;
    }
    puts("Editing occuars succesfully");
    system("pause");
    system("cls");
    menu();
}
void transact( float money[]) {
    printf("Enter the account number that want to make money transaction :");
    unsigned short int acc_num;
    scanf("%lu" , &acc_num);
    printf("Account Money PLan :             Account Available Money \n");
    switch (depositType[acc_num - 1]) {
    case 1:
        printf("saving                          ");
        break;
    case 2:
        printf("current                         ");
        break;
    case 3:
        printf("investment                      ");
        break;
    default:
        printf("Data missing Error Please check for this account details");
        break;
    };
    printf(" %.2f \n" , money[acc_num - 1]);
    printf("PLease, Choice transact Operation type where \n %s\n %s\n",
           "1- Deposit",
           "2- Withdraw"
           );
    float temp_money_holder = money[acc_num - 1];
    unsigned int client_choice = 0;
    scanf("%u" , &client_choice);
    float client_money = 0.0;
    switch (client_choice) {
    case 1:
        printf("Enter the amount of money you will deposit :");
        scanf("%f" , &client_money);
        temp_money_holder += client_money;
        break;
    case 2:
        printf("Enter the amount of money you will withdraw :");
        scanf("%f" , &client_money);
        temp_money_holder -= client_money;
        break;
    default:
        printf("Invalid answer");
        break;
    }
    money[acc_num - 1] = temp_money_holder;
    printf("\nThe new money in the client account = %.2f \n" , money[acc_num - 1]);
    system("pause");
    menu();

}
void erase() {
    printf("Please, Enter the account number you want to delete it :");
    unsigned int acc_num;
    scanf("%u" , &acc_num);
    printf("Name : %s \t ID : %s \n" , names[acc_num - 1] , national[acc_num - 1]);
    printf("ARE YOU SURE THAT YOU WANT TO DELETE THIS ACCOUNT (press 1 for yes) \n");
    unsigned int employ_choice;
    scanf("%u" , &employ_choice);
    if (employ_choice != 1) {
        puts("Removing account proccess stoped !!");
        system("pause");
    } else {
        unsigned int detecter = acc_num -1;
        names[detecter][0] = '\0';
        date_birth[detecter][0] = '\0';
        national[detecter][0] = '\0';
        address[detecter][0] = '\0';
        phone[detecter][0] = '\0';
        depositType[detecter] = '\0';
        money[detecter] = 0;
        for (; detecter < number_of_accounts ; detecter++) {
            strcpy(names[detecter], names[detecter + 1]);
            strcpy(date_birth[detecter], date_birth[detecter + 1]);
            strcpy(national[detecter], national[detecter + 1]);
            strcpy(address[detecter], address[detecter + 1]);
            strcpy(phone[detecter], phone[detecter + 1]);
            depositType[detecter] = depositType[detecter + 1];
            money[detecter] = money[detecter + 1];
        }
        number_of_accounts--;
    }
    menu();
}
void see() {
    printf("Enter the Account number you want to see its informations :");
    int acc_num;
    scanf("%d" , &acc_num);
    printf("Acc.num : ");
    printf("%15d  " , acc_num);
    printf("\nName    : ");
    printf("%15s  " , names[acc_num - 1]);
    printf("\nID      : ");
    printf("%15s  " , national[acc_num - 1]);
    printf("\nAddress : ");
    printf("%15s  " , address[acc_num - 1]);
    printf("\nBirth   : ");
    printf("%15s  " , date_birth[acc_num - 1]);
    printf("\nPhone   : ");
    printf("%15s  " , phone[acc_num - 1]);
    printf("\nPlan    : ");
    switch (depositType[acc_num - 1]) {
    case 1:
        printf("         saving  ");
        break;
    case 2:
        printf("        current  ");
        break;
    case 3:
        printf("     investment  ");
        break;
    default:
        printf("Data missing");
        break;
    };
    printf("\nWallet  : ");
    printf("%15.2f  " , money[acc_num - 1]);
    puts("");
    puts("For going back to menu");
    system("pause");
    system("cls");
    menu();
}
void search() {
    char name_input[10];
    printf("Enter the name of the client you want to search for :");
    scanf("%s" , name_input);
    int client_counter;
    for (client_counter = 0 ; client_counter < number_of_accounts ; client_counter++) {
        if (!strcmp(name_input, names[client_counter])) { // the value is equal 0 if the two strings are equal so we reverse (!)
            puts("Yes We Have Ahmed account");
            printf("Acc.num : ");
            printf("%15d  " , client_counter + 1);
            printf("\nName    : ");
            printf("%15s  " , names[client_counter]);
            printf("\nID      : ");
            printf("%15s  " , national[client_counter]);
            printf("\nAddress : ");
            printf("%15s  " , address[client_counter]);
            printf("\nBirth   : ");
            printf("%15s  " , date_birth[client_counter]);
            printf("\nPhone   : ");
            printf("%15s  \n" , phone[client_counter]);
            puts("Searching Proccess Completed");
            system("pause");
            menu();
        }
    }
    puts("Unfortnatily, We didint find An account with this name");
    system("pause");
    menu();
}
void sort() {
    puts("The Elements of the array After sorting \n");
    char detect , names_counter;
    printf("     Name:     Data Birth      National ID           Address             Phone\n");
    for (detect = 'A' ; detect >= 'A' && detect <= 'Z' ; detect++) { // checking for the first character for all names
        for (names_counter = 0; names[names_counter][0] != '\0' ; names_counter++) {
            if (names[names_counter][0] == detect) { // if the first character is equal to detect char variable make condition
                printf("%10s   %12s   %14s   %15s   %15s\n" ,
                names[names_counter],
                date_birth[names_counter],
                national[names_counter],
                address[names_counter],
                phone[names_counter]);
            }
        }
    }
    puts("Sorting Proccess Completed.");
    system("pause");
    menu();

}
