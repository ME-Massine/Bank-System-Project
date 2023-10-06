#ifndef CHANGE_USERNAME_H
#define CHANGE_USERNAME_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "colors.h"
#include "glob.h"

char Nfilename[100], NUsername[30], Nfilename_1[100];
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
        cyan();
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

    sprintf(filename_1, "Users\\%s_logs.txt", Username);   // * Original log filename
    sprintf(Nfilename_1, "Users\\%s_logs.txt", NUsername); // * New log filename

    // ? Rename the user's main file
    int result = rename(filename, Nfilename);

    // ? Rename the user's log file
    int result_1 = rename(filename_1, Nfilename_1);

    if (result == 0)
    {
        yellow();
        strcpy(Username, NUsername);
        printf("\nUsername has been changed successfully .");
        strcpy(filename, Nfilename);
        cyan();
    }
    else
    {
        yellow();
        printf("\nThe file could not be renamed.");
        cyan();
    }

    if (result_1 != 0)
    {
        yellow();
        printf("\nThe log file could not be renamed.");
        cyan();
    }

    sleep(1);
}

#endif
