#include <stdio.h>
#include <windows.h>
#include "colors.h"
#include "glob.h"

char Username_1[50], password_1[30];
int funds, bal_1, bal_2;
bool exists;

void funds_transfer()
{
    FILE *fp;

    do
    {
        here:
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
            yellow();
            printf("\nYou can't transfer funds to yourself.");
            Sleep(1000);
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

        if (funds < 0 || (funds % 100) > 0)
        {
            yellow();
            printf("\n\nDeposit value must be multiplier of 100.");
            sleep(2);
            goto here;
        }

        // Getting balance from the sender account
        fp = fopen(filename, "r");
        fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, &bal);
        fclose(fp);

        if (funds > bal)
        {
            printf("\nNot enough money in account.");
            Sleep(1500);
            continue;
        }
        else
        {
            bal = bal - funds;

            fp = fopen(filename, "w");
            if (fp == NULL)
            {

                perror("Error opening file for writing");
                exit(EXIT_FAILURE);
            }
            fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, bal);
            fclose(fp);

            char password_recipient[30], phone_number_recipient[30];

            fp = fopen(filename_1, "r");
            if (fp == NULL)
            {
                perror("Error opening recipient's file for reading");
                exit(EXIT_FAILURE);
            }

            fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password_recipient, phone_number_recipient, &bal_2);

            fclose(fp);

            // ? Updating recipient's balance

            bal_2 = bal_2 + funds;
            fp = fopen(filename_1, "w");
            if (fp == NULL)
            {
                perror("Error opening recipient's file for writing");
                exit(EXIT_FAILURE);
            }

            fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password_recipient, phone_number_recipient, bal_2);

            fclose(fp);

            printf("\nNew balance: %d\n", bal);

            break;
        }

    } while (exists == false);
}