#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct  s_art {
    char *name;
    int price;
};



int searchPrice(struct s_art **arts, char *name);

#endif