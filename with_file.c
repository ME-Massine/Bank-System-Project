#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void check_bal()
{
    int bal, with;

    FILE *fp;

    // ! reading balance value

    fp = fopen("C:\\Users\\Massine\\Desktop\\bal.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(fp))
    {
        bal = fscanf(fp, "%d", &bal);
    }
    fclose(fp);

    // ! reading depo value
    fp = fopen("C:\\Users\\Massine\\Desktop\\depo.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &with);
    }
    fclose(fp);

    // ! calculating balance
    bal = bal + depo;
    printf("your balance is %d", bal);
    fp = fopen("C:\\Users\\Massine\\Desktop\\bal.txt", "w");
    fprintf(fp, "%d", bal);

    fclose(fp);

    // ! clearing depo value
    fp = fopen("C:\\Users\\Massine\\Desktop\\depo.txt", "w");
    depo = 0;
    fprintf(fp, "%d", depo);

    fclose(fp);
}