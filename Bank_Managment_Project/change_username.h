#ifndef CHANGE_USERNAME_H
#define CHANGE_USERNAME_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "colors.h"
#include "glob.h"

char Nfilename[100], NUsername[30];
bool exists;

void change_username()
{
    FILE *fp;

    do
    {
        system("cls");
        printf("Your current Username is: ");
        Purple();

        printf("%s", Username);
        printf("\n\nInsert your new Username: ");
        Purple();
        scanf("%s", NUsername);
        cyan();

        sprintf(Nfilename, "Users\\%s.txt", NUsername);

        fp = fopen(Nfilename, "r");
        if (fp != NULL)
        {
            exists = true;
            yellow();
            printf("\n\nUsername already taken.");
            sleep(1);
            cyan();
        }
        else
            exists = false;
        fclose(fp);
    } while (exists == true);

    int result = rename(filename, Nfilename);

    if (result == 0)
    {
        yellow();
        printf("\nUsername has been chanfed successfully .");
        strcpy(filename, Nfilename);
        cyan();
    }
    else
    {
        yellow();
        printf("\nThe file could not be renamed.");
        cyan();
    }
    sleep(1);
}

#endif