#include "header.h"

char    *getString(int  *text,int  size,struct s_list *head)
{
    char    *string = NULL;
    int     curr_char = 0;
    int     i = 0;
    struct  s_list  *curr = NULL;

    curr = head;
    if(NULL ==(string = malloc(sizeof(char) * size)+1))
        return NULL;
    while(size != 0)
    {
        curr_char = text[i];
        while(curr_char != 0)
        {
            if(text[i] < 0)
            {
                curr_char++;
                curr = curr->prev;
            }
            else
            {
                curr_char--;
                curr = curr->next;
            }
        }
        string[i] = curr->character;
        i++;
        size--;
    }
    return string;
}
struct  s_list   *addItem(struct s_list *head, struct s_list *item)
{
    struct  s_list  *tmp = NULL;
    struct  s_list  *prev = NULL;

    if (head == NULL)
    {
        head = item;
        item->next = NULL;
        item->prev = NULL;
    }
    else
    {
        tmp = head;
        prev = head;
        item->next = head;
        head->prev = item;
        while(tmp->next != NULL && tmp->next != head)
        {
            tmp = tmp->next;
            tmp->prev = prev;
            prev = tmp;
        }
        tmp->next = item;
        item->prev = tmp;
    }
    return head;
}

struct s_list   *initStruct(char ch)
{
    struct s_list   *item;
    if (NULL == (item = malloc(sizeof (struct s_list))))
                return NULL;
    else
    {
        item->next = NULL;
        item->prev = NULL;
        item->character = ch;
    }
    return item;
}

char    *precious(int *text, int size)
{
    struct  s_list  *item;
    struct  s_list  *head = NULL;
    int     i = 0;
    char    *string = NULL;

    if(text != NULL && size != 0)
    {
        if(NULL == (string = malloc(sizeof(char) * size + 1)))
            return NULL;
        while(CS[i] != '\0')
        {
            item = initStruct(CS[i]);
            head = addItem(head, item);
            i++;
        }
        string = getString(text, size, head);
    }
    return string;
}

int main(int ac, char **av)
{
    int size = 0;
    int i = 0;
    int *int_arr;
    int j = 1;
    char *string = NULL;

    size = ac - 1;
    if(NULL == (int_arr = malloc(sizeof(int) * size + 1)))
        return -1;
    while(av[j])
    {
        int_arr[i] = atoi(av[j]);
        j++;
        i++;
    }
    string = precious(int_arr, size);
    return 1;
}