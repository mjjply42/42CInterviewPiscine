#include    "header.h"

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

struct  s_stone *setStones(struct s_stone *head, struct s_stone *stone)
{
    struct  s_stone *tmp = NULL;
    if(head == NULL)
        head = stone;
    else
    {
        tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = stone;
    }
    return head;
}

struct  s_stone *initStone(int  num)
{
    struct  s_stone *stone = NULL;
    if(NULL == (stone = malloc(sizeof(struct s_stone))))
        return NULL;
    stone->size = num;
    stone->next = NULL;
    return stone;
}

int         main()
{   int arr[] = {2,2,2,5,5,6,4,4,4,1,1,9,9,9,9,25,25,25,0,0,0,0,15,15,50,50,34,34,34,34,21,21,21};
    int i = 0;
    struct s_stone  *stone_list = NULL;
    struct s_stone  *stone = NULL;
    while(i < (int)sizeof(arr)/4)
    {
        stone = initStone(arr[i]);
        stone_list = setStones(stone_list,stone);
        i++;
    }
    sortStones(&stone_list);
    struct s_stone *test = stone_list;
    while(test)
    {
        printf(" %i ",test->size);
        test = test->next;
    }
    printf("\n");
    return 1;
}