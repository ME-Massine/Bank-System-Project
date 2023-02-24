#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

char Username[50], password[30], Cpassword[30], filename[100], line[100], Username_1[50], filename_1[100];
int bal, funds;

void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void Purple()
{
    printf("\033[0;35m");
}

void cyan()
{
    printf("\033[0;36m");
}

void reset()
{
    printf("\033[0m");
}

void login()
{

    int i = 3;
    bool exists;
    do
    {
        system("cls");
        printf("Enter your Username: ");
        scanf("%s", Username);

        sprintf(filename, "Users\\%s.txt", Username);
        FILE *fp = fopen(filename, "r");
        if (fp != NULL)
        {
            exists = true;
        }
        else
            exists = false;
        fclose(fp);
    } while (exists == false);

    printf("Enter your password: ");
    scanf("%s", password);

    //! read first line of file into line variable
    FILE *fp = fopen(filename, "r");
    fgets(line, 100, fp);
    fclose(fp);

    //! gets password from first line in file
    if (sscanf(line, "password: %s", Cpassword) == 1)
    {
        if (strcmp(Cpassword, password) == 0)
        {
            yellow();
            printf("\nSuccesfully logged in.\n");
            reset();
            cyan();
            sleep(1);
        }
        else
        {
            printf("Incorrect password.\n");
            sleep(1);
            exit(EXIT_FAILURE);
        }
    }
};

void check_bal()
{
    FILE *fp;
    red();
    printf("Balance\n");
    reset();

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nbalance: %d", password, &bal);

    fclose(fp);
    // ? printing balance

    cyan();
    printf("\nyour balance is %dDH", bal);
    reset();
};

void sign_up()
{
    char Username[30], password[30], Cpassword[30], filename[30];
    int bal = 0;
    bool exists;

    FILE *fp;
    system("cls");

    do
    {
        system("cls");
        printf("Enter your Username: ");
        scanf("%s", Username);

        sprintf(filename, "Users\\%s.txt", Username);
        fp = fopen(filename, "r");
        if (fp != NULL)
        {
            exists = true;
            printf("Username already taken.");
            sleep(1);
        }
        else
            exists = false;
        fclose(fp);

    } while (exists == true);

    printf("Enter your password: ");
    scanf("%s", password);
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s", password);
    fprintf(fp, "\nbalance = %d", bal);

    fclose(fp);
    system("cls");
    exit(EXIT_SUCCESS);
};

void acc()
{
    char choice;

    printf("Please select an option from the menu below:\n\n");
    printf("a. Login \n");
    printf("b. Sign up \n");
    printf("c. Exit \n\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'a':
        login();
        break;
    case 'b':
        sign_up();
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }
};

void check_with()
{
    int with, choice;

    FILE *fp;

    // ! reading balance value

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "password: %s\nbalance: %d", password, &bal);
    fclose(fp);

    // ! getting withdraw value
    system("cls");

    red();
    printf("Withdraw\n");
    reset();

    cyan();
    printf("\nhow much do you want to withdraw: ");
    printf("\n\n1. 200DH\t\t");
    printf("2. 400DH\n");
    printf("3. 800DH\t\t");
    printf("4. 1000DH\n");
    printf("5. insert amount\t");
    printf("6. quit\n\n");
    printf("Type choice (1/2/3/4/5/6): ");
    scanf("%d", &choice);
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
        scanf("%d", &with);
        break;
    case 6:
        break;
    default:
        printf("Invalid input");
        system("cls");
        break;
    }

    if (with < 0)
    {
        printf("invalid value");
    }
    if (with > bal)
    {
        printf("not enough money in account");
    }
    else
    {
        // ? calculating balance
        bal = bal - with;
        fp = fopen(filename, "w");
        fprintf(fp, "password: %s\nbalance: %d", password, bal);

        fclose(fp);

        // ! reseting with value
        with = 0;
    }
    reset();
};

void check_depo()
{
    int depo;
    FILE *fp;
    // ! getting depo value
    red();
    printf("Deposit\n");
    reset();

    cyan();
    printf("\nhow much do you want to deposit: ");
    scanf("%d", &depo);

    if (depo <= 0)
    {
        printf("invalid value");
    }

    // ! reading bal value
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "password: %*s\nbalance: %d", &bal);

    fclose(fp);

    bal = bal + depo;

    // ! storing bal value
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nbalance: %d", password, bal);

    fclose(fp);

    // ! clearing depo value

    depo = 0;

    fclose(fp);
    reset();
}

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
        scanf("%s", Username_1);

        if (strcmp(Username, Username_1) == 0)
        {
            printf("\nYou can't transfer funds to yourself.");
            sleep(1);
            continue;
        }

        //! Opening recipient's account
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
        scanf("%d", &funds);

        // Getting balance from the sender account
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
            bal_1 = bal_1 - funds;

            fp = fopen(filename, "w");
            fprintf(fp, "password: %s\nbalance: %d", password, bal_1);
            fclose(fp);

            fp = fopen(filename_1, "r");
            fscanf(fp, "password: %s\nbalance: %d", password_1, &bal_2);
            fclose(fp);

            bal_2 = bal_2 + funds;
            fp = fopen(filename_1, "w");
            fprintf(fp, "password: %s\nbalance: %d", password_1, bal_2);
            fclose(fp);

            printf("\nNew balance: %d\n", bal_1);
            break;
        }

    } while (exists == false);
};
