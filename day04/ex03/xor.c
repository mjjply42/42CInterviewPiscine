#include "header.h"

char    *getXor(char *a, char *b)
{
    char    *binary = NULL;
    int i = 0;
    if(NULL == (binary = malloc(sizeof(char) * 6 + 1)))
        return NULL;
    binary[6] = '\0';
    while(i < 6)
    {
        if(a[i] != b[i])
            binary[i] = '1';
        else
            binary[i] = '0';
        i++;
    }

    return binary;
}

int     toInt(char *bits)
{
    int number = 0;
    int place = 1;
    int i = strlen(bits)-1;
    while(i >= 0)
    {
        if(bits[i] == '1')
            number += place;
        i--;
        place *= 2;
    }
    return number;
}