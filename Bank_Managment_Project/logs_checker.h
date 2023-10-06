#ifndef LOGS_CHECKER_H
#define LOGS_CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include "glob.h"
#include "colors.h"
#include "logs_validator.h"

void check_for_changes(int index)
{
    if (strcmp(password, temp_password) != 0 && index == 2)
    {
        log_activity("Password was changed.");
    }

    if (strcmp(phone_number, temp_phone_number) != 0 && index == 3)
    {
        log_activity("Phone number was changed.");
    }

    if (bal != temp_bal && index == 4)
    {
        log_activity("withdrew money");
    }
    if (bal != temp_bal && index == 5)
    {
        log_activity("deposited money");
    }

    if (strcmp(Username, temp_Username) != 0 && index == 1)
    {
        log_activity("Username was updated.");
    }
}

#endif