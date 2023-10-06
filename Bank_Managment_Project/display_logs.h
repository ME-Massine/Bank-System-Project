#ifndef DISPLAY_LOGS_H
#define DISPLAY_LOGS_H

#include <conio.h>
#include <stdio.h>
#include <unistd.h>
#include "glob.h"
#include "colors.h"



void display_logs(){
    
    FILE *fp; 
  
    char c,choice;
    sprintf(filename_1, "Users\\%s_logs.txt", Username);
  
    
    fp = fopen(filename_1, "r"); 
    if (fp == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0);
    } 
  
    // ? Read contents from file 
    c = fgetc(fp); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fp); 
    } 
  
    fclose(fp); 

    red();
    printf("\n\npress any key to exit.");
    getch();

}

#endif