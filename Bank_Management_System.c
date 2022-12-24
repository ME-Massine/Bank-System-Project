#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "login.c"
#include "bal_file.c"
#include "depo_file.c"
#include "with_file.c"
#include "color_file.c"
int main()
{
    int bal;
    float depo, with;
    int choice, i, j = 0;
    char choice_3;

    // ! user login function:

    login();
    // * clearing the terminal
    system("cls");
    for (i = 0; i < 10; i--)
    {
        // * ATM menu
        red();
        printf("\n--------------- ATM --------------\n\n");
        reset();
        cyan();
        printf("1.balance");
        printf("\t\t2.deposit\n");
        printf("3.get help");
        printf("\t\t4.withdraw\n");
        printf("5.acc info");
        printf("\t\t6.quit\n");

        // ! getting choice from user

        printf("\n\n__________________");
        printf("\npick an option: ");
        scanf(" %d", &choice);
        printf("\n\n");

        FILE *fp;

        switch (choice)
        {
        case 1:
            // ! prints balance and clears terminal after 2s

            check_bal();
            sleep(2);
            system("cls");
            break;

        case 2:
            // ! gets depo value and clears terminal after 2s

            check_depo();
            printf("\n\n");
            sleep(2);
            system("cls");
            break;
        case 3:

            printf("1_check your balance\n\n");
            printf("2_deposit a certain amount of money into your bank account\n\n");
            printf("3_get help\n\n");
            printf("4_get your money of the bank\n\n");
            printf("5_get all your acc informations\n\n");
            printf("6_quit the program.\n\n");
            printf("go back to menu(n/y): ");
            scanf(" %c", &choice_3);

            switch (choice_3)
            {
            case 'y':
                system("cls");
                break;
            case 'n':
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("invalid input(y/n)");
                break;
            }

            break;

        case 4:
            // ! gets depo value and clears terminal after 2s

            check_with();
            sleep(2);
            system("cls");
            break;

        case 5:

            printf("balance: %.3f\n", bal);
            printf("last deposit was: ");
            break;
        case 6:
            fp = fopen("C:\\Users\\Massine\\Desktop\\depo.txt", "w");
            depo = 0;
            fprintf(fp, "%d", depo);
            fclose(fp);
            fp = fopen("C:\\Users\\Massine\\Desktop\\bal.txt", "w");
            bal = 0;
            fprintf(fp, "%d", bal);
            fclose(fp);
            exit(EXIT_SUCCESS);
            reset();
            break;

        default:
            printf("invalid");
            break;
        };
    }
}
