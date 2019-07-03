#include "header.h"

int     *getArr(struct s_stone **stone, int size)
{
    int *int_arr = NULL;
    int num = 0;
    struct  s_stone *tmp = NULL;
    if(NULL == (int_arr = malloc(sizeof(int) * size + 1)))
        return NULL;
    bzero(int_arr,size);
    tmp = *stone;
    while(tmp != NULL)
    {
        num = tmp->size;
        int_arr[num]++;
        tmp = tmp->next;
    }
    return int_arr;
}

int     getSize(struct s_stone **stone)
{
    int     largest = 0;
    struct  s_stone *tmp = NULL;
    tmp = *stone;
    largest = tmp->size;
    while(tmp != NULL)
    {
        if(largest < tmp->size)
            largest = tmp->size;
        tmp = tmp->next;
    }
    return largest;
}

void    sortStones(struct s_stone **stone)
{
    int     large;
    int     *int_arr = NULL;
    int     index = 0;
    struct  s_stone *tmp = NULL;
    large = getSize(stone);
    int_arr = getArr(stone, large);
    tmp = *stone;
    while(tmp != NULL)
    {
        if(int_arr[index] != 0)
        {
            tmp->size = index;
            int_arr[index]--;
            tmp = tmp->next;
        }
        else
            index++;
    }
}