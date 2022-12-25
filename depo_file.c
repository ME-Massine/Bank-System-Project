#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void check_bal()
{
    int bal, depo;

    FILE *fp;

    // ! reading balance value

    fp = fopen("text files\\bal.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d", &bal);
    }
    fclose(fp);

    // ? printing balance
    printf("your balance is %d", bal);
    fp = fopen("text files\\bal.txt", "w");
    fprintf(fp, "%d", bal);

    fclose(fp);

}
