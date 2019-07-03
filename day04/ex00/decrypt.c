#include "header.h"

char    *getSum(char *a, char *b)
{
    char *binary = NULL;
    int i = 6;
    int carry = 0;
    if(NULL == (binary = malloc(sizeof(char) * 6 + 1)))
        return NULL;
    binary[6] = '\0';
    i--;
    while(i >= 0)
    {
        if((a[i] == '0' && b[i] == '0') || (a[i] == '1' && b[i] == '1'))
        {
            binary[i] = '0';
            if(carry == 1)
            {
                binary[i] = '1';
                carry--;
            }
            if(a[i] != '0' || b[i] != '0')
                carry = 1;
        }
        else
        {
            binary[i] = '1';
            if(carry == 1)
                binary[i] = '0';
        }    
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