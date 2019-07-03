#include "header.h"

char        *dequeue(struct s_queue *queue)
{
    char    *message = NULL;
    struct  s_item  *tmp = NULL;
    tmp = queue->first;
    message = tmp->message;
    queue->first = queue->first->next;
    return message;
}

char        *peek(struct s_queue *queue)
{
    char    *message = NULL;
    message = queue->first->message;
    return message;
}

int         isEmpty(struct  s_queue *queue)
{
    int     status = 0;
    if(queue->first != NULL)
        status = 0;
    else
        status = 1;
    return  status;
}

struct      s_item  *initItem(char  *message)
{
    struct  s_item *item = NULL;
    if(NULL == (item = malloc(sizeof(struct  s_item))))
        return NULL;
    item->message = message;
    item->next = NULL;
    return item;
}

void        enqueue(struct s_queue  *queue, char *message)
{
    struct  s_item  *item = NULL;
    item = initItem(message);
    if(queue->first == NULL && queue->last == NULL)
    {
        queue->first = item;
        queue->last = item;
    }
    else
    {
        queue->last->next = item;
        queue->last = item;
    }
}

struct      s_queue *queueInit()
{
    struct  s_queue *queue = NULL;
    if(NULL == (queue = malloc(sizeof(struct s_queue))))
        return NULL;
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}