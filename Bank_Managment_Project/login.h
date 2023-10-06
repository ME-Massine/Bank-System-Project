#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <unistd.h>
#include "colors.h"
#include "glob.h"

char Cpassword[30], line[100];
bool exists;

void login()
{

    do
    {
    again:;
        system("cls");
        red();
        printf("Login");
        cyan();
        printf("\n\nEnter your Username: ");
        Purple();
        scanf("%s", Username);
        cyan();

        sprintf(filename, "Users\\%s.txt", Username);
        FILE *fp = fopen(filename, "r");
        if (fp != NULL)
        {
            exists = true;
        }
        else
        {
            exists = false;
            yellow();
            printf("\nUsername doesn't exist.");
            cyan();
        }
        fclose(fp);
        sleep(1);
    } while (exists == false);

    printf("\nEnter your password: ");
    Purple();
    scanf("%s", password);
    cyan();

    //! read first line of file into line variable
    FILE *fp = fopen(filename, "r");
    fgets(line, 100, fp);
    fclose(fp);

    //! gets password from first line in file
    if (sscanf(line, "password: %s", Cpassword) == 1)
    {
        do
        {
            if (strcmp(Cpassword, password) == 0)
            {
                yellow();
                printf("\nSuccesfully logged in.\n");
                cyan();
                sleep(1);
            }
            else
            {
                yellow();
                
                printf("\nIncorrect password.\n");
                cyan();
                sleep(1);
                goto again;
            }
        } while (strcmp(Cpassword, password) != 0);
    }
}

#endif