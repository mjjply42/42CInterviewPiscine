#include "header.h"

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

struct  s_player    **mergeSort(struct s_player **player)
{
    int len = 0;
    while(player[len])
        len++;
    sort(player, len);
    return player;
}