#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void check_depo()
{
    int depo, bal;

    FILE *fp;
    fp = fopen("text files\\depo.txt", "w");
    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    // ! getting depo value

    printf("\nhow much do you want to deposit: ");
    scanf("%d", &depo);
    fprintf(fp, "%d", depo);

    fclose(fp);

    if (depo <= 0)
    {
        printf("invalid value");
    }
    fclose(fp);

    // ! reading bal value
    fp = fopen("text files\\bal.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &bal);
    }
    fclose(fp);

    bal = bal + depo;

    // ! storing bal calue
    fp = fopen("text files\\bal.txt", "w");
    fprintf(fp, "%d", bal);

    fclose(fp);

    // ! clearing depo value
    fp = fopen("text files\\depo.txt", "w");
    depo = 0;
    fprintf(fp, "%d", depo);

    fclose(fp);
}
