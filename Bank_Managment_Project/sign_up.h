#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "colors.h"
#include "glob.h"

void sign_up()
{
    int bal = 0;
    bool exists;
    FILE *fp;
    FILE *fp_1;

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

    /*                   Users\\Username_logs.txt           */
    sprintf(filename_1, "Users\\%s_logs.txt", Username);

    fp_1 = fopen(filename_1, "w");
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, bal);

    fclose(fp_1);
    fclose(fp);
    system("cls");
}

#endif