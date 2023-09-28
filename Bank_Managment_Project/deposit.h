#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "glob.h"

int depo;

void deposit()
{
    FILE *fp;

    // ! getting depo value
    red();
    printf("Deposit\n");

    cyan();
    printf("\nhow much do you want to deposit: ");
    Purple();
    scanf("%d", &depo);
    cyan();

    if (depo <= 0 || (depo % 100) != 0)
    {
        printf("invalid value");
    }

    // ! reading bal value
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "password: %*s\nphone_number: %s\nbalance: %d", phone_number, &bal);

    fclose(fp);

    bal += depo;

    // ! storing bal value
    fp = fopen(filename, "w");
    fprintf(fp, "password: %s\nphone_number: %s\nbalance: %d", password, phone_number, bal);

    fclose(fp);

    // ! clearing depo value

    depo = 0;

    fclose(fp);
    reset();
}