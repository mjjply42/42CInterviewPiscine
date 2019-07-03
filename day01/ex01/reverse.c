#include "header.h"

void    printReverse(struct s_node *head)
{
    struct  s_node  *curr = head;

    if(curr->next != NULL)
    {
        printReverse(curr->next);
        putchar(' ');
    }
    printf("%s", curr->word);
}