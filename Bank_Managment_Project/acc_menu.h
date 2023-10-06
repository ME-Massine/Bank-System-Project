#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "login.h"
#include "sign_up.h"
#include "glob.h"

void acc_menu()
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
        system("cls");
        exit(EXIT_FAILURE);
        break;
    }
}