#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

struct s_node 
{
    char *word;
    struct s_node *next;
};

void printReverse(struct s_node *lst);

#endif