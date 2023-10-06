#ifndef LOGS_VALIDATOR_H
#define LOGS_VALIDATOR_H

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "glob.h"
#include "colors.h"

void log_activity(const char *message)
{
    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    FILE *fp;
    sprintf(filename_1, "Users\\%s_logs.txt", Username);

    fp = fopen(filename_1, "a");

    if (fp == NULL)
    {
        yellow();
        perror("Failed to open the log file");
        return;
    }

    fprintf(fp, "[%02d-%02d-%04d %02d:%02d] %s\n",
            date.tm_mday, date.tm_mon + 1, date.tm_year + 1900, date.tm_hour, date.tm_min, message);
    fclose(fp);
}

#endif