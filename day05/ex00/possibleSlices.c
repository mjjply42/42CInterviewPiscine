#include "header.h"

void    getPossibilities(int size, struct s_array *array)
{
    struct s_array *tmp = NULL;

    if(size == 0 && array->sum)
        arrayPrint(array);
    if(!size)
        return;
    for(int i = 1; i <= size; i++)
    {
        tmp = arrayClone(array);
        arrayAppend(tmp, i);
        getPossibilities((size-i), tmp);
    }
}

void    printPossibleSlices(int pizzaSize)
{
    getPossibilities(pizzaSize, arrayInit());
}