#include "header.h"

void countSort(unsigned char *utensils,int n)
{
    int int_arr[15] = {};
    int i = 0;
    int j = 0;

    while(i < n)
    {
        int_arr[utensils[i]]++;
        i++;
    }
    i = 0;
    while(i < 15 - 1)
    {
        int_arr[i + 1] += int_arr[i];
        i++;
    }
    while(i > 0)
    {
        int_arr[i] = int_arr[i -1];
        i--;
    }
    i = 0;
    while(j < n)
    {   
        if(j != int_arr[i + 1] && i <= 15)
        {
            utensils[j] = i;
            j++;
        }
        else
            i++;
        if(i == 15)
        {
            utensils[j] = i;
            j++;
        }
    }
}