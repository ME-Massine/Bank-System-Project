#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


void login()
{
    char name[30];
    char Ninfo[30];
    char password[30];
    char choice;

    FILE *fp;

    printf("a.login \n");
    printf("b.sign in \n");
    printf("c.quit \n");
    printf("enter an option from the menu: ");
    scanf(" %c", &choice);

    switch (choice)
    {

    case 'a':
        fp = fopen("C:\\Users\\Massine\\Desktop\\a.txt", "w");
        if (fp == NULL)
        {
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter your name: ");
        fgets(name, 30, stdin);
        fputs(name, fp);
        fgets(name, 30, stdin); // gets the name from user
        fputs(name, fp);        // writes data in file

        printf("Enter Password: ");

        fgets(password, 30, stdin); // gets the password from user
        fputs(password, fp);        // writes data in file
        fclose(fp);                 // closes and saves file
        break;
    case 'b':

        fp = fopen("C:\\Users\\Massine\\Desktop\\b.log", "a");
        if (fp == NULL)
        {
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter your name: ");
        fgets(name, 30, stdin);
        fputs(name, fp);
        fgets(name, 30, stdin); // gets the name from user
        fputs(name, fp);        // writes data in file

        printf("name info is %c", Ninfo);
        printf("Enter Password: ");

        fgets(password, 30, stdin); // gets the password from user
        fputs(password, fp);        // writes data in file

        fclose(fp); // closes and saves file
        break;

    case 'c':
        break;

    default:
        printf("invalid");
        exit(EXIT_FAILURE);
        break;
    }
};