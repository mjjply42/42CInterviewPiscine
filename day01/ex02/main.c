#include "header.h"
struct  s_node  *initList(struct s_node *node_list, struct s_node *node)
{
    struct  s_node  *tmp = NULL;
    if(node_list == NULL)
    {
        node_list = node;
        node->next = NULL;
    }
    else
    {
        tmp = node_list;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
    return node_list;
}
struct  s_node  *initNode(char *str)
{
    struct s_node *node = NULL;
    if(str != NULL)
    {
        if(NULL == (node = malloc(sizeof(struct s_node))))
            return NULL;
        node->word = str;
        node->next = NULL;
    }
    return node;
}

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

int     main(int ac, char **av)
{
    struct  s_node  *node_list = NULL;
    struct  s_node  *node = NULL;
    int     i = 1;

    if(ac < 2)
        return -1;
    while (ac - 1 != 0)
    {
        node = initNode(av[i]);
        node_list = initList(node_list, node);
        i++;
        ac--;
    }
    printReverseV2(node_list);
    printf("\n");
    return 1;
}