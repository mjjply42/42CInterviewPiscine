#include    "header.h"

void    merge(struct s_player **left, int l_len, struct s_player **right, int r_len, struct s_player **Arr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int stamp = 0;

    while(i < l_len && j < r_len)
    {
        if(left[i]->score > right[j]->score)
            Arr[k] = left[i++];
        else if(left[i]->score == right[j]->score)
        {
            while((left[i]->timeStamp[stamp] - right[i]->timeStamp[stamp]) == 0)
                stamp++;
            if((left[i]->timeStamp[stamp] - right[i]->timeStamp[stamp]) > 0)
                Arr[k] = right[j++];
            else
                Arr[k] = left[i++];
        }
        else
            Arr[k] = right[j++];
        k++;
    }
    while(i < l_len)
        Arr[k++] = left[i++];
    while(j < r_len)
        Arr[k++] = right[j++];
}
void    sort(struct s_player **player, int size)
{
    int mid = size/2;
    int i = 0;
    struct s_player **left;
    struct s_player **right;
    if(size < 2)
        return;
    if(NULL == (left = malloc(sizeof(struct s_player) * mid)))
        return;
    if(NULL == (right = malloc(sizeof(struct s_player) * (size - mid))))
        return;
    while(i < mid)
    {
        left[i] = player[i];
        i++;
    }
    while(i < size)
    {
        right[i - mid] = player[i];
        i++;
    }
    sort(left,mid);
    sort(right,(size - mid));
    merge(left,mid,right,(size - mid),player);
}

struct s_player    **mergeSort(struct s_player **player)
{
    int len = 0;
    while(player[len])
        len++;
    sort(player, len);
    return player;
}

struct  s_player    *initPlayer(int score, char *name, char *timestamp)
{
    struct  s_player    *player = NULL;
    if(NULL ==(player = malloc(sizeof(struct s_player))))
     return NULL;
    player->score = score;
    player->name = name;
    player->timeStamp = timestamp;

    return player;
}

int     main()
{
    struct  s_player    *player = NULL;
    struct  s_player    **player_list = NULL;
    int arr[] = {2,2,1,32,21,45621,0,7,3,2};
    int size = (int)sizeof(arr)/4;
    char *arr2[] = {"Charlie", "Michael", "Steven", "Xavier", "Pete", "Dbag400", "Marke", "Eth4n", "Noo8", "Prick"};
    char *arr3[] = {"2015-11-03 07:41:39", "2015-11-03 07:41:03", "2017-02-09 06:01:32", "2015-11-02 03:23:34", "2015-11-09 23:45:39", "2010-02-03 10:41:54", "2017-04-03 10:12:39", "2009-11-02 07:41:45", "2015-12-03 07:41:31", "2015-11-03 07:41:37"};
    if(NULL == (player_list = malloc(sizeof(struct s_player) * 10 + 1)))
    return -1;
    int i = 0;
    while(i < size)
    {
        player = initPlayer(arr[i], arr2[i], arr3[i]);
        player_list[i] = player;
        i++;
    }
    i = 0;
    printf("------------BEFORE---------\n");
    while(i < size)
    {
        printf("Name: %s  Score: %i  Stamp: %s\n ",player_list[i]->name, player_list[i]->score, player_list[i]->timeStamp);
        i++;
    }
    //printf("\n");
    mergeSort(player_list);
    i = 0;
    printf("----------AFTER---------\n");
    while(i < size)
    {
        printf("Name: %s  Score: %i  Stamp: %s\n ",player_list[i]->name, player_list[i]->score, player_list[i]->timeStamp);
        i++;
    }
    //printf("\n");

    return 1;
}