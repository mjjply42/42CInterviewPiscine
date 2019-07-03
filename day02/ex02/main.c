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

struct  s_player    *initPlayer(int score, char *name)
{
    struct  s_player    *player = NULL;
    if(NULL ==(player = malloc(sizeof(struct s_player))))
     return NULL;
    player->score = score;
    player->name = name;
    return player;
}

int     main()
{
    struct  s_player    *player = NULL;
    struct  s_player    **player_list = NULL;
    int arr[] = {2,4,1,32,21,45621,0,7,3,23};
    char *arr2[] = {"Charlie", "Michael", "Steven", "Xavier", "Pete", "Dbag400", "Marke", "Eth4n", "Noo8", "Prick"};
    int i = 0;
    if(NULL == (player_list = malloc(sizeof(struct s_player) * 10 + 1)))
    return -1;
    while(i < (int)sizeof(arr)/4)
    {
        player = initPlayer(arr[i], arr2[i]);
        player_list[i] = player;
        i++;
    }
    i = -1;
    printf("Before Sorting: \n");
    while(player_list[++i] != NULL)
        printf("Name: %s   Score: %i\n", player_list[i]->name,player_list[i]->score);
    printf("\n\n");
    quickSort(player_list);
    i = -1;
    printf("After Sorting: \n");
    while(player_list[++i] != NULL)
        printf("Name: %s   Score: %i\n", player_list[i]->name,player_list[i]->score);
    printf("\n");
    return 1;
}