#include "header.h"

double  find(int size, double *price_list, double highest, double tmp)
{
    double cost = 0;
    if(size == 0)
        return tmp;
    for(int i = 1; i <= size; i++)
    {
        cost = find(size - i, price_list, highest, (tmp + price_list[i]));
        if(cost > highest)
            highest = cost;
    }
    return highest;
}

double bestPrice(int pizzaSize, double *prices)
{
    double deal = prices[pizzaSize];
    double value = 0;
    value = find(pizzaSize, prices, deal, 0);
    return value;
}