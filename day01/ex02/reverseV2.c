#include "header.h"

void    *pop(struct s_stack *stack)
{
    struct  s_item *tmp = NULL;
    tmp = stack->item;
    stack->item = tmp->next;
    return(tmp);
}

void    push(struct s_stack *stack, char *word)
{
    struct  s_item  *item = NULL;
    if(NULL ==(item = malloc(sizeof(struct s_item))))
        return ;
    item->word = word;
    item->next = stack->item;
    stack->item = item;
}

struct  s_stack *stackInit()
{
    struct s_stack  *stack;
    if(NULL == (stack = malloc(sizeof(struct s_stack))))
        return NULL;
    stack->item = NULL;
    return stack;
}

void    printReverseV2(struct s_node *lst)
{
    struct  s_stack *stack = NULL;
    struct  s_node  *curr = NULL;
    struct  s_item  *drop = NULL;
    curr = lst;
    struct  s_node  *test = lst;
    while(test != NULL)
        test = test->next;
    stack = stackInit();
    while(curr != NULL)
    {
        push(stack, curr->word);
        curr = curr->next;
    }
    while(stack->item != NULL)
    {
        drop = (struct s_item *)pop(stack);
        printf("%s", drop->word);
        if(stack->item != NULL)
        putchar(' ');
    }
}