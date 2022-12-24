#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void check_with()
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
        with = fscanf(fp, "%d", &bal);
    }
    fclose(fp);

    // ! getting withdraw value
    fp = fopen("C:\\Users\\Massine\\Desktop\\with.txt", "w");

    printf("\nhow much do you want to withdraw: ");
    scanf("%d", &with);
    fprintf(fp, "%d", with);
    if (with <=0 )
    {
        exit();
    }
    
    // ! reading withdraw value
    fp = fopen("C:\\Users\\Massine\\Desktop\\with.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &with);
    }
    fclose(fp);

    // ? calculating balance
    bal = bal - with;
    fp = fopen("C:\\Users\\Massine\\Desktop\\bal.txt", "w");
    fprintf(fp, "%d", bal);

    fclose(fp);

    // ! clearing with value
    fp = fopen("C:\\Users\\Massine\\Desktop\\depo.txt", "w");
    with = 0;
    fprintf(fp, "%d", with);

    fclose(fp);
}
