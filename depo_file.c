#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void check_depo()
{
    int depo;

    FILE *fp;
    fp = fopen("C:\\Users\\Massine\\Desktop\\depo.txt", "w");
    if (fp == NULL)

    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nhow much do you want to deposit: ");
    scanf("%d", &depo);
    fprintf(fp, "%d", depo);

    fclose(fp);
}