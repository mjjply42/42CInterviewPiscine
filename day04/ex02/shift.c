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

char   *flippy(char *bin)
{
    int i = 0;
    while(bin[i] != '\0')
    {
        bin[i] = (bin[i] == '1'? '0':'1');
        i++;
    }
    return bin;
}

char    *leftShift(char *bin, int k)
{
    char *shifted = NULL;
    int i = 0;
    if(NULL == (shifted = malloc(sizeof(char) * 6 + 1)))
        return NULL;
    shifted[6] = '\0';
    while(i < 6)
    {
        shifted[i] = '0';
        i++;
    }
    if(k == 6)
        return shifted;
    i = 0;
    while(i < 6)
    {
        if((6-k) <= i)
            shifted[i] = '0';
        else
            shifted[(abs((k-i)-k))] = bin[k+i];
        i++;
    }
    return shifted;
}

char    *rightShift(char *bin, int k)
{
    char *shifted = NULL;
    int i = 0;
    if(NULL == (shifted = malloc(sizeof(char) * 6 + 1)))
        return NULL;
    shifted[6] = '\0';
    while(i < 6)
    {
        shifted[i] = '1';
        i++;
    }
    if(k == 6)
        return shifted;
    i = 0;
    while(i < 6)
    {
            if(k + i < 6)
                shifted[k+i] = bin[i];
            i++;
    }
    return shifted;
}

char    *getSub(char *a, char *b)
{
    b = flippy(b);
    b = getSum(b, "000001");
    b = getSum(a,b);
    return b;
}

int     toInt(char *bits)
{
    int number = 0;
    int place = 1;
    int neg = 0;
    char *test = NULL;
    test = bits;
    int i = strlen(bits)-1;
    if (bits[i] == '1')
    {
        test = flippy(test);
        test = getSum(test, "000001");
        neg = 1;
    }
    while(i >= 1)
    {
        if(test[i] == '1')
            number += place;
        i--;
        place *= 2;
    }
    if(neg == 1)
        bits = flippy(bits);
    return (neg == 1? (number*-1):(number));
}