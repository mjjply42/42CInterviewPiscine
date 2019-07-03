#include "header.h"

int    pop(struct s_stack *stack)
{
    struct  s_item *tmp = NULL;
    tmp = stack->item;
    stack->item = tmp->next;
    return(tmp->idx);
}

void    push(struct s_stack *stack, int index)
{
    struct  s_item  *item = NULL;
    if(NULL ==(item = malloc(sizeof(struct s_item))))
        return ;
    item->idx = index;
    item->next = stack->item;
    stack->item = item;
}

struct s_stack *initStack()
{
    struct  s_stack *stack = NULL;
    if(NULL == (stack= malloc(sizeof(struct s_stack))))
        return NULL;
    stack->item = NULL;
    return stack;
}

void    prompt()
{
    printf("?: ");
}

char    *console()
{
    char    *input = NULL;
    char    mess[MESS_SIZE];
    int     index = 0;
    struct  s_stack *stack = NULL;

    if(NULL == (input = malloc(sizeof(char) * MESS_SIZE + 1)))
        return NULL;
    bzero(mess, MESS_SIZE);
    stack = initStack();
    while(1)
    {
        prompt();
        fgets(input, MESS_SIZE , stdin);
        input[strlen(input) - 1] = '\0';
        if((strcmp(input, "UNDO") == 0))
        {
            index = pop(stack);
            bzero(mess + index, MESS_SIZE - index);
        }
        else if(strcmp(input, "SEND") == 0)
            break;
        else
        {
            strncpy(mess + index, input, strlen(input));
            push(stack,index);
            index += strlen(input);
            mess[index] = ' ';
            index++;
        }
        printf("%s\n", mess);
    }
    return (strdup(mess));
}