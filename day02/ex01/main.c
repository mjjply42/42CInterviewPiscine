#include    "header.h"

 void insertionSort(struct s_player **players)
 {
    int i = 1;
    int hole = i;
    int value = players[i]->score;
    char *name = NULL;
    while(players[i] != NULL)
    {
        hole = i;
        value = players[i]->score;
        name = players[i]->name;
        while(hole > 0 && players[hole - 1]->score < value)
        {
            players[hole]->score = players[hole -1]->score;
            players[hole]->name = players[hole -1]->name;
            hole = hole -1;
        }
        players[hole]->score = value;
        players[hole]->name = name;
        i++;
    }
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
    insertionSort(player_list);
    return 1;

}