#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

char Username[50], password[30], Cpassword[30], filename[100], line[100], Username_1[50], filename_1[100], phone_number[11];
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

    //! read first line of file into line variable
    FILE *fp = fopen(filename, "r");
    fgets(line, 100, fp);
    fclose(fp);

    //! gets password from first line in file
    if (sscanf(line, "password: %s", Cpassword) == 1)
    {
        do
        {
            if (strcmp(Cpassword, password) == 0)
            {
                yellow();
                printf("\nSuccesfully logged in.\n");
                cyan();
                sleep(1);
            }
            else
            {
                yellow();
                printf("\nIncorrect password.\n");
                cyan();
                goto again;
                sleep(1);
            }
        } while (strcmp(Cpassword, password) != 0);
    }
}

void check_bal()
{
    FILE *fp;
    red();
    printf("Balance\n");

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nbalance: %d", password, &bal);

    fclose(fp);
    // ? printing balance

    cyan();
    printf("\nyour balance is %dDH", bal);
    reset();
}

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
            exists = false;
        fclose(fp);

        printf("\n\nEnter your phone number (06XXX): ");
        scanf("\r%s", phone_number);

        if (strlen(phone_number) != 10)
        {
            yellow();
            printf("\n\nPhone number must be 10 digits. ");
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

back:;
    system("cls");

    red();
    printf("Withdraw\n");

    cyan();
    printf("\nhow much do you want to withdraw: ");
    printf("\n\n1. 200DH\t\t");
    printf("2. 400DH\n");
    printf("3. 800DH\t\t");
    printf("4. 1000DH\n");
    printf("5. insert amount\t");
    red();
    printf("6. quit\n\n");
    cyan();
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
        system("cls");
        break;
    }

    if (with < 0)
    {
        yellow();
        printf("\ninvalid value");
        cyan();
        sleep(1);
        goto back;
    }
    if (with > bal)
    {
        yellow();
        printf("\nnot enough money in account");
        cyan();
        sleep(1);
        goto back;
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
exit:;
    sleep(1);
}

void check_depo()
{
    int depo;
    FILE *fp;
    // ! getting depo value
    red();
    printf("Deposit\n");

    cyan();
    printf("\nhow much do you want to deposit: ");
    Purple();
    scanf("%d", &depo);
    cyan();

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
        Purple();
        scanf("%s", Username_1);
        cyan();

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
        Purple();
        scanf("%d", &funds);
        cyan();

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
}

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
            yellow();
            printf("\n\nUsername already taken.");
            sleep(1);
            cyan();
        }
        else
            exists = false;
        fclose(fp);
    } while (exists == true);

    int result = rename(filename, Nfilename);

    if (result == 0)
    {
        yellow();
        printf("\nThe file is renamed successfully.");
        cyan();
    }
    else
    {
        yellow();
        printf("\nThe file could not be renamed.");
        cyan();
    }
    sleep(1);
}

void password_change()
{

    char Cupassword[30], Confirm_password[30];
    int result;

    FILE *fp;

    do
    {
        system("cls");
        printf("Enter your current password: ");
        Purple();
        scanf("%s", Cupassword);
        cyan();

        result = strcmp(Cupassword, password);

        if (result != 0)
        {
            yellow();
            printf("\nIncorrect password.");
            cyan();
            sleep(1);
        }

    } while (result != 0);

    printf("\nEnter new password: ");
    Purple();
    scanf("%s", Cupassword);
    cyan();
    printf("\nConfirm your new password: ");
    Purple();
    scanf("%s", Confirm_password);
    cyan();

    if (strcmp(Cupassword, Confirm_password) == 0)
    {

        fp = fopen(filename, "w");
        fprintf(fp, "password: %s\nbalance: %d", Confirm_password, bal);

        fclose(fp);
        yellow();
        printf("\nPassword changed succesfully.");
        cyan();
    }
    else
    {
        yellow();
        printf("\nPasword doesn't match.");
        cyan();
    }
    sleep(1);
}

//! changing the phone number
void phone_number_change()
{
    do
    {
        system("cls");
        red();
        printf("Changing phone number");
        cyan();
        printf("Enter you new phone number: ");

        if (strlen(phone_number) != 10)
        {
            yellow();
            printf("\n\nPhone number must be 10 digits. ");
            sleep(1);
            cyan();
        }

    } while (strlen(phone_number) != 10);
}
void Acc_info()
{

    int choice, choice_1;

    FILE *fp;

    red();
    printf("Account Informations");

    cyan();
    printf("\n\nUsername: %s", Username);
    // printf("Phone number: %s",Phone_number);

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, &bal);

    fclose(fp);

    printf("\ncurrent balance: %dDH", bal);

    printf("\n\n1. Edit profile ");
    printf("\t\t2. Go back");
    printf("\n\npick an option: ");
    Purple();
    scanf("%d", &choice);
    cyan();

    switch (choice)
    {
    case 1:

        system("cls");
        red();
        printf("Account informations");

        cyan();
        printf("\n\nwhat do you want to change? ");
        printf("\n\n1. Username");
        printf("\n2. Password");
        printf("\n3. Phone number");

        printf("\n\npick an option: ");
        Purple();
        scanf("%d", &choice_1);
        cyan();

        switch (choice_1)
        {
        case 1:
            Username_change();
            break;

        case 2:
            password_change();
            break;

        case 3:
            break;

        default:
            break;
        }

        break;

    case 2:
        system("cls");
        break;

    default:
        system("cls");
        printf("\nInvalid input");
        break;
    }
}
