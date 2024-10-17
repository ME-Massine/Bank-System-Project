#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

// Global variables to store user details
char Username[50], password[30], Cpassword[30], filename[100], line[100], Username_1[50], filename_1[100], phone_number[11];
int bal, funds;

// Functions to change text color in the console
void red() { printf("\033[1;31m"); }
void yellow() { printf("\033[1;33m"); }
void Purple() { printf("\033[0;35m"); }
void cyan() { printf("\033[0;36m"); }
void reset() { printf("\033[0m"); }

// Function to handle user login
void login()
{
    bool exists;
    do
    {
    again:;
        system("cls");
        red();
        printf("Login");
        cyan();
        printf("\n\nEnter your Username: ");
        Purple();
        scanf("%s", Username);
        cyan();

        sprintf(filename, "Users\\%s.txt", Username);
        FILE *fp = fopen(filename, "r");
        if (fp != NULL)
        {
            exists = true;
        }
        else
        {
            exists = false;
            yellow();
            printf("\nUsername doesn't exist.");
            cyan();
        }
        fclose(fp);
        sleep(1);
    } while (exists == false);

    printf("\nEnter your password: ");
    Purple();
    scanf("%s", password);
    cyan();

    FILE *fp = fopen(filename, "r");
    fgets(line, 100, fp);
    fclose(fp);

    if (sscanf(line, "password: %s", Cpassword) == 1)
    {
        do
        {
            if (strcmp(Cpassword, password) == 0)
            {
                yellow();
                printf("\nSuccessfully logged in.\n");
                cyan();
                sleep(1);
            }
            else
            {
                yellow();
                printf("\nIncorrect password.\n");
                cyan();
                sleep(1);
                goto again;
            }
        } while (strcmp(Cpassword, password) != 0);
    }
}

// Function to check the account balance
void check_bal()
{
    FILE *fp;
    red();
    printf("Balance\n");

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nbalance: %d", password, &bal);
    fclose(fp);

    cyan();
    printf("\nYour balance is %dDH", bal);
    reset();
}

// Function to handle user sign up
void sign_up()
{
    char Username[30], password[30], filename[30];
    int bal = 0;
    bool exists;
    FILE *fp;

    do
    {
        system("cls");
        red();
        printf("Sign up");
        cyan();
        printf("\n\nEnter your Username: ");
        Purple();
        scanf("%s", Username);
        cyan();

        sprintf(filename, "Users\\%s.txt", Username);
        fp = fopen(filename, "r");
        if (fp != NULL)
        {
            exists = true;
            yellow();
            printf("\nUsername already taken.");
            sleep(1);
            goto here;
        }
        else
        {
            exists = false;
        }
        fclose(fp);

        printf("\n\nEnter your phone number (06XXX): ");
        scanf("\r%s", phone_number);

        if (strlen(phone_number) != 10)
        {
            yellow();
            printf("\n\nPhone number must be 10 digits.");
            sleep(1);
        }
    here:;
    } while ((exists == true) || (strlen(phone_number) != 10));

    printf("\nEnter your password: ");
    Purple();
    scanf("%s", password);
    cyan();
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, bal);
    fclose(fp);
    system("cls");
    exit(EXIT_SUCCESS);
}

// Function to display the account menu for login or signup
void acc()
{
    char choice;
    yellow();
    printf("Please select an option from the menu below:\n\n");
    cyan();
    printf("a. Login \n");
    printf("b. Sign up \n");
    printf("c. Exit \n\n");
    printf("Enter your choice: ");
    Purple();
    scanf(" %c", &choice);
    cyan();

    switch (choice)
    {
    case 'a':
        login();
        break;
    case 'b':
        sign_up();
        break;
    default:
        yellow();
        printf("\nInvalid input");
        cyan();
        system("cls");
        exit(EXIT_FAILURE);
        break;
    }
}

// Function to handle money withdrawal
void check_with()
{
    int with, choice;
    FILE *fp;

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nbalance: %d", password, &bal);
    fclose(fp);

back:;
    system("cls");
    red();
    printf("Withdraw\n");
    cyan();
    printf("\nHow much do you want to withdraw:\n");
    printf("1. 200DH\t\t2. 400DH\n3. 800DH\t\t4. 1000DH\n");
    printf("5. Insert amount\t6. Quit\n\n");
    printf("Type choice (1/2/3/4/5/6): ");
    Purple();
    scanf("%d", &choice);
    cyan();
    switch (choice)
    {
    case 1:
        with = 200;
        break;
    case 2:
        with = 400;
        break;
    case 3:
        with = 800;
        break;
    case 4:
        with = 1000;
        break;
    case 5:
        system("cls");
        printf("Insert an amount: ");
        Purple();
        scanf("%d", &with);
        cyan();
        break;
    case 6:
        goto exit;
        break;
    default:
        yellow();
        printf("\nInvalid input");
        cyan();
        sleep(1);
        goto back;
    }

    if (with < 0 || with > bal)
    {
        yellow();
        printf("\nInvalid or insufficient funds.");
        cyan();
        sleep(1);
        goto back;
    }

    bal -= with;
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nbalance: %d", password, bal);
    fclose(fp);

exit:
    sleep(1);
}

// Function to handle deposit
void check_depo()
{
    int depo;
    FILE *fp;
    red();
    printf("Deposit\n");

    cyan();
    printf("\nHow much do you want to deposit: ");
    Purple();
    scanf("%d", &depo);
    cyan();

    if (depo <= 0)
    {
        printf("Invalid value");
    }

    fp = fopen(filename, "r");
    fscanf(fp, "password: %*s\nbalance: %d", &bal);
    fclose(fp);

    bal += depo;
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nbalance: %d", password, bal);
    fclose(fp);

    reset();
}

// Function to transfer funds between accounts
void fundsTransfer()
{
    char password_1[30];
    int bal_1, bal_2;
    bool exists;
    FILE *fp;

    do
    {
        system("cls");
        red();
        printf("Transfer funds\n");
        cyan();
        printf("\nThe recipient's account Username: ");
        Purple();
        scanf("%s", Username_1);
        cyan();

        if (strcmp(Username, Username_1) == 0)
        {
            printf("\nYou can't transfer funds to yourself.");
            sleep(1);
            continue;
        }

        sprintf(filename_1, "Users\\%s.txt", Username_1);
        fp = fopen(filename_1, "r");
        if (fp != NULL)
        {
            exists = true;
            fclose(fp);
        }
        else
        {
            exists = false;
            printf("\nRecipient's account not found.");
            Sleep(1500);
            continue;
        }

        printf("\nThe amount of money you wish to transfer: ");
        Purple();
        scanf("%d", &funds);
        cyan();

        fp = fopen(filename, "r");
        fscanf(fp, "password: %s\nbalance: %d", password, &bal_1);
        fclose(fp);

        if (funds > bal_1)
        {
            printf("\nNot enough money in account.");
            Sleep(1500);
            continue;
        }
        else
        {
            bal_1 -= funds;
            fp = fopen(filename, "w");
            fprintf(fp, "password: %s\nbalance: %d", password, bal_1);
            fclose(fp);

            fp = fopen(filename_1, "r");
            fscanf(fp, "password: %s\nbalance: %d", password_1, &bal_2);
            fclose(fp);

            bal_2 += funds;
            fp = fopen(filename_1, "w");
            fprintf(fp, "password: %s\nbalance: %d", password_1, bal_2);
            fclose(fp);

            printf("\nNew balance: %d\n", bal_1);
            break;
        }
    } while (exists == false);
}

// Function to change username
void Username_change()
{
    char Nfilename[100], NUsername[30];
    bool exists;
    FILE *fp;

    do
    {
        system("cls");
        printf("Insert your new Username: ");
        Purple();
        scanf("%s", NUsername);
        cyan();

        sprintf(Nfilename, "Users\\%s.txt", NUsername);
        fp = fopen(Nfilename, "r");

        if (fp != NULL)
        {
            exists = true;
            printf("\nUsername is already taken.");
            Sleep(1500);
        }
        else
        {
            exists = false;
            rename(filename, Nfilename);
            sprintf(filename, "%s", Nfilename);
            printf("\nSuccessfully changed your Username.");
        }
        fclose(fp);
    } while (exists == true);
}

// Function to change password
void password_change()
{
    char Npassword[30];
    FILE *fp;
    system("cls");
    printf("Insert your new password: ");
    Purple();
    scanf("%s", Npassword);
    cyan();

    fp = fopen(filename, "r");
    fscanf(fp, "password: %*s\nbalance: %d", &bal);
    fclose(fp);

    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nbalance: %d", Npassword, bal);
    fclose(fp);
}

// Function to change phone number
void phone_number_change()
{
    char Nphone_number[11];
    FILE *fp;
    system("cls");
    printf("Insert your new phone number: ");
    Purple();
    scanf("%s", Nphone_number);
    cyan();

    fp = fopen(filename, "r");
    fscanf(fp, "password: %*s\nbalance: %d", &bal);
    fclose(fp);

    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, Nphone_number, bal);
    fclose(fp);
}
