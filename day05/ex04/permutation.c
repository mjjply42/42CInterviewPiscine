#include "header.h"

void mutations(char *str, int *count, char *result, int level/*,int *county*/)
{
    if(level == (int)strlen(str))
    {
        printf("%s\n", result);
        //*county += 1;;
        return;
    }
    for(int i = 0; i < (int)strlen(str); i++)
    {
        if(count[i] == 0)
            continue;
        result[level] = str[i];
        count[i]--;
        mutations(str,count,result,level +1/*,county*/);
        count[i]++;
    }
    return;
}


void printPermutations(char *str)
{
    //int county = 0;
    int *count = malloc(sizeof(int) * strlen(str) + 1);
    char *result = malloc(sizeof(char) * strlen(str) + 1);
    for(int i = 0; i <= (int)strlen(str); i++)
        count[i] = 1;
    result[strlen(str)] = '\0'; 
    mutations(str, count, result, 0/*,&county*/);
    //printf("There are %i permutations for %s\n", county, str);
}