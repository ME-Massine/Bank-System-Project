#include <stdio.h>
#include <unistd.h>
#include "colors.h"
#include "glob.h"

void change_phone_number()
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