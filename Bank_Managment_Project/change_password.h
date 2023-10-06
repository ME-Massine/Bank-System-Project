#ifndef PASSWORD_CHANGE_H
#define PASSWORD_CHANGE_H

#include <stdio.h>
#include <unistd.h>
#include "colors.h"
#include "glob.h"

char Cupassword[30], Confirm_password[30];

void password_change()
{
    FILE *fp;

    do
    {
    here:;
        system("cls");
        cyan();
        printf("Enter your current password: ");
        Purple();
        scanf("%s", Cupassword);
        cyan();

        if (strcmp(Cupassword, password) != 0)
        {
            yellow();
            printf("\nIncorrect password.");
            cyan();
            sleep(1);
        }

    } while (strcmp(Cupassword, password) != 0);

    printf("\nEnter new password: ");
    Purple();
    scanf("%s", Cupassword);
    if (strcmp(Cupassword, password) == 0)
    {
        yellow();
        printf("\n\nThe new password must be different from the current password");
        sleep(2);
        goto here;
    }
        
    cyan();
    printf("\nConfirm your new password: ");
    Purple();
    scanf("%s", Confirm_password);
    cyan();

    if (strcmp(Cupassword, Confirm_password) == 0)
    {

        fp = fopen(filename, "w");
        fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", Confirm_password, phone_number, bal);

        fclose(fp);
        yellow();
        strcpy(password, Confirm_password);
        printf("\nPassword changed succesfully.");

        cyan();
    }
    else
    {
        yellow();
        printf("\nPasword doesn't match.");
        cyan();
        sleep(1);
        goto here;
    }
    sleep(1);
}

#endif