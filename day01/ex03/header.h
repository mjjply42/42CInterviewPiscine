#ifndef HEADER_H
# define HEADER_H
# define MESS_SIZE (255)

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

struct  s_item
{
    int     idx;
    struct  s_item  *next;
};

struct  s_stack
{
    struct  s_item  *item;
};

char    *console(void);

#endif