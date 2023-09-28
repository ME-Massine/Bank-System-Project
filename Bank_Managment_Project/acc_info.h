#ifndef ACC_INFO_H
#define ACC_INFO_H

#include <stdio.h>
#include "colors.h"
#include "change_password.h"
#include "change_username.h"
#include "glob.h"

void acc_info()
{
    int choice, choice_1;

    FILE *fp;

    red();
    printf("Account Informations");

    cyan();
    printf("\n\nUsername: %s", Username);

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
            change_username(filename);
            break;

        case 2:
            password_change();
            break;

        case 3:
            change_phone_number();
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

#endif
