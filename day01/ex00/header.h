#ifndef HEADER_H
# define HEADER_H
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <math.h>

struct s_list
{
    char character;
    struct s_list *next;
    struct s_list *prev;
};

#endif