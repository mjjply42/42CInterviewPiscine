#include "header.h"

size_t		getSize(struct s_player **player)
{
	int				size;

	size = 0;
	while (player[size] != NULL)
		size += 1;
	return (size);
}

void    ft_swap(struct s_player *a, struct s_player *b)
{
    struct s_player tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     partition(struct s_player **player, int start, int end)
{
    int p_index = start;
    int pivot = player[end]->score;
    int i = start;
    while(i < end)
    {
        if(player[i]->score >= pivot)
        {
            ft_swap(player[i], player[p_index]);
            p_index++;
        }
        i++;
    }
    ft_swap(player[p_index], player[end]);
    return p_index;
}

void    sort(struct s_player **player, int start, int end)
{
    int p_index = 0;
    if(start < end)
    {
        p_index = partition(player, start, end);
        sort(player, start, p_index - 1);
        sort(player, p_index + 1, end);
    }
}

void    quickSort(struct s_player **player)
{
    int end = getSize(player) - 1;
    sort(player, 0, end);
}