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

struct      s_item 
{
    char *message; 
    struct  s_item *next;
};

struct      s_queue 
{
    struct  s_item *first;
    struct  s_item *last;
};


struct      s_queue *queueInit(void);
char        *dequeue(struct s_queue *queue);
int         isEmpty(struct s_queue *queue);
void        enqueue(struct s_queue *queue, char *message); char *peek(struct s_queue *queue);

#endif