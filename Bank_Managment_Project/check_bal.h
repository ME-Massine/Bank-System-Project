#include <stdio.h>
#include "colors.h"
#include "glob.h"

void check_bal()
{
    FILE *fp;
    red();
    printf("Balance\n");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Failed to open the file");
        return;
    }
    fscanf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, &bal);

    fclose(fp);
    // ? printing balance

    cyan();
    printf("\nyour balance is %dDH", bal);
    reset();
}