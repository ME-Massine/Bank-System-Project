#include <stdio.h>
#include <unistd.h>
#include "colors.h"
#include "glob.h"

void change_phone_number()
{
    char NEW_phone_number[11];
    FILE *fp;
    do
    {
        system("cls");
        red();
        printf("Changing phone number\n\n");
        cyan();
        printf("Enter your new phone number: ");
        Purple();
        scanf("%s", NEW_phone_number);
        cyan();

        if (strlen(NEW_phone_number) != 10)
        {
            yellow();
            printf("\n\nPhone number must be 10 digits. ");
            sleep(1);
            cyan();
        }

    } while (strlen(NEW_phone_number) != 10);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        yellow();
        perror("Failed to open the file");
        return;
    }
    strcpy(phone_number, NEW_phone_number);
    fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, NEW_phone_number, bal);
    fclose(fp);

    sleep(1);
}
