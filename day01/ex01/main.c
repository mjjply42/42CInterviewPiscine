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

struct  s_node  *addNode(struct s_node *head, struct s_node *node)
{
    struct  s_node  *tmp = NULL;

    if (head == NULL)
    {
        head = node;
        node->next = NULL;
    }
    else
    {
        tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
    return head;
}

struct  s_node  *initStruct(char *string)
{
    struct s_node *node = NULL;

    if(string != NULL)
    {
        if(NULL == (node = malloc(sizeof(char) * strlen(string)+1)))
            return NULL;
        node->word = strdup(string);
        node->next = NULL;
    }
    return node;
}

int main(int ac, char **av)
{
    struct s_node *node = NULL;
    struct s_node *head = NULL;
    int i = 1;

    while(ac -1 != 0)
    {
        node = initStruct(av[i]);
        head = addNode(head, node);
        ac--;
        i++;
    }
    printReverse(head);
    printf("\n");
    return 1;
}