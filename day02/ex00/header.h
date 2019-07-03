#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

struct s_stone
{
    int size;
    struct s_stone *next;
};

void sortStones(struct s_stone **stone);

#endif