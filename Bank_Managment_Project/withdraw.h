#include <stdio.h>
#include "colors.h"
#include "glob.h"

void withdraw()
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
    fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, &bal);
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
        fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, bal);

        fclose(fp);

        // ! reseting with value
        with = 0;
    }
    reset();
exit:;
    sleep(1);
}
