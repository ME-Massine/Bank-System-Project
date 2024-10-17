#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "Functions.h"

int main()
{
    int choice, i;
    char choice_3;
    system("cls");

    // Welcome message
    red();
    printf("Welcome to the Bank Management System!\n\n");
    reset();

    // User login or signup
    acc();

    // Clearing the terminal
    system("cls");

    // Main ATM menu loop
    for (i = 0; i <= 10; i++)
    {
        // Display ATM menu
        red();
        printf("\n--------------- Welcome to ATM --------------\n\n");
        reset();
        cyan();
        printf("1. Check Balance");
        printf("\n2. Deposit Money\n");
        printf("3. Get Help");
        printf("\n4. Withdraw Money\n");
        printf("5. Account Information ");
        yellow();
        printf("(Upcoming Feature!)");
        reset();
        cyan();
        printf("\n6. Transfer Funds ");
        reset();
        printf("\x1b[32m(New Feature!)\x1b[0m\n");
        red();
        printf("7. Exit");
        reset();
        cyan();

        // Getting user choice
        printf("\n\nPick an option: ");
        Purple();
        scanf(" %d", &choice);
        cyan();

        // Switch statement for menu options
        switch (choice)
        {
        case 1:
            // Check balance
            system("cls");
            check_bal();
            Sleep(1500);
            system("cls");
            break;

        case 2:
            // Deposit money
            system("cls");
            check_depo();
            printf("\n\n");
            Sleep(500);
            system("cls");
            break;

        case 3:
            // Help menu
            system("cls");
            red();
            printf("=== HELP ===\n\n");
            cyan();
            printf("1. Check your balance\n");
            printf("2. Deposit a certain amount of money into your bank account\n");
            printf("3. Get help\n");
            printf("4. Withdraw your money from the bank\n");
            printf("5. Get all your account information\n");
            printf("6. Transfer funds to another account\n");
            printf("7. Quit the program\n\n");
            printf("Go back to the menu? (y/n): ");
            Purple();
            scanf(" %c", &choice_3);
            cyan();

            // Submenu for returning or exiting
            switch (choice_3)
            {
            case 'y':
                system("cls");
                break;
            case 'n':
                system("cls");
                exit(EXIT_SUCCESS);
                break;
            default:
                yellow();
                printf("\nInvalid input");
                sleep(1);
                cyan();
                system("cls");
                break;
            }
            break;

        case 4:
            // Withdraw money
            check_with();
            Sleep(500);
            system("cls");
            break;

        case 5:
            // Account Information (Upcoming feature)
            system("cls");
            // Acc_info();
            system("cls");
            break;

        case 6:
            // Transfer funds
            fundsTransfer();
            sleep(1);
            system("cls");
            break;

        case 7:
            // Exit
            printf("Have a nice day.\n");
            sleep(1);
            system("cls");
            exit(EXIT_SUCCESS);

        default:
            // Invalid input handling
            yellow();
            printf("\nInvalid input. Please try again.\n");
            sleep(1);
            cyan();
            system("cls");
            break;
        };
    }
    reset();
}
