#ifndef ACC_INFO_H
#define ACC_INFO_H

#include <stdio.h>
#include "colors.h"
#include "change_password.h"
#include "change_username.h"
#include "glob.h"
#include "logs_checker.h"
#include "logs_validator.h"

void acc_info()
{
    int choice, choice_1, index;

    FILE *fp;

    red();
    printf("Account Informations");

    cyan();
    printf("\n\nUsername: ");
    Purple();
    printf("%s", Username);

    fp = fopen(filename, "r");
    fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, &bal);

    fclose(fp);
    cyan();
    printf("\nCurrent balance:");
    Purple();
    printf(" %dDH", bal);
    cyan();

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
            index = 1;
            strcpy(temp_Username, Username);
            change_username();
            check_for_changes(index);

            break;

        case 2:
            index = 2;
            strcpy(temp_password, password);
            password_change();
            check_for_changes(index);

            break;

        case 3:
            index = 3;
            strcpy(temp_phone_number, phone_number);
            change_phone_number();
            check_for_changes(index);

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
