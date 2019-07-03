#include "header.h"

char   *flippy(char *bin)
{
    int i = 0;
    if (bin[i] == '~')
    {
        i++;
        while(bin[i] != '\0')
        {
            bin[i] = (bin[i] == '1'? '0':'1');
            i++;
        }
    }
    bin++;
    bin =  strdup(bin);
    return bin;
}

char    *getOr(char *a, char *b)
{
    char *binary = NULL;
    int i = 0;
    if(NULL == (binary = malloc(sizeof(char) * 4 + 1)))
        return NULL;
    binary[4] = '\0';
    a = strlen(a) > strlen(b)? flippy(a): a;
    b = strlen(b) > strlen(a)? flippy(b): b;
    i = strlen(a)-1;
    while(i >= 0)
    {
        if(a[i] == '~' || b[i] == '~')
            break;
        if(a[i] == '0' && b[i] == '0')
            binary[i] = '0';
        else
            binary[i] = '1';
        i--;
    }
    return binary;
}

char    *getAnd(char *a, char *b)
{
    char *binary = NULL;
    int i = 0;
    if(NULL == (binary = malloc(sizeof(char) * 4 + 1)))
        return NULL;
    binary[4] = '\0';
    a = strlen(a) > strlen(b)? flippy(a): a;
    b = strlen(b) > strlen(a)? flippy(b): b;
    i = strlen(a)-1;
    while(i >= 0)
    {
        if(a[i] == '~' || b[i] == '~')
            break;
        if(a[i] == '1' && b[i] == '1')
            binary[i] = '1';
        else
            binary[i] = '0';
        i--;
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