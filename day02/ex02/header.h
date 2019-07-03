#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

struct s_player
{ 
    int score;
    char *name;
};

void quickSort(struct s_player **players);

#endif