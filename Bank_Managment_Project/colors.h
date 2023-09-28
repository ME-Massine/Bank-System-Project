#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>

void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void Purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}
void reset()
{
    printf("\033[0m");
}

#endif
