#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void check_with()
{
    int bal, with;

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
        with = fscanf(fp, "%d", &bal);
    }
    fclose(fp);

    // ! getting withdraw value
    fp = fopen("text files\\with.txt", "w");

    printf("\nhow much do you want to withdraw: ");
    scanf("%d", &with);
    // ! reading withdraw value
    fp = fopen("text files\\with.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &with);
    }
    fclose(fp);

    if (with < 0)
    {
        printf("invalid value");
        exit(EXIT_FAILURE);
    }
    

    // ? calculating balance
    bal = bal - with;
    fp = fopen("text files\\bal.txt", "w");
    fprintf(fp, "%d", bal);

    fclose(fp);

    // ! clearing with value
    fp = fopen("text files\\depo.txt", "w");
    with = 0;
    fprintf(fp, "%d", with);

    fclose(fp);
}
