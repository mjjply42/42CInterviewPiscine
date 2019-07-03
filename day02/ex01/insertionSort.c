#include "header.h"

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