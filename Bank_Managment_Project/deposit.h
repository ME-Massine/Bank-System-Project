#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"
#include "glob.h"



void deposit()
{
    int depo, i=0;
    FILE *fp;

    red();
    printf("Deposit\n");

    
        here:
        fflush(stdin);
        system("cls");
        cyan();
        printf("\nhow much do you want to deposit: ");
        Purple();
        scanf("%d", &depo);
        cyan();
        if (depo < 0 || (depo % 100) > 0)
        {
            yellow();
            printf("\n\nDeposit value must be multiplier of 100.");
            sleep(2);
            goto here;
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