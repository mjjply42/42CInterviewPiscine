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
    char *timeStamp;
};

struct s_player **mergeSort(struct s_player **players);


#endif