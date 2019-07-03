#include "header.h"

double  find(int size, double *prices, double *highest)
{
    double cost = 0.0;
    if(size == 0 || (highest[size] != 0))
        return highest[size];
    highest[size] = prices[size];
    for(int i = 1; i < size; i++)
    {
        cost = highest[i] + find(size - i, highest, prices);
        if(cost > highest[size])
            highest[size] = cost;
    }
    return (highest[size]);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
    double highest[pizzaSize + 1];
    double result = 0;
    for(int i = 0; i <= pizzaSize; i++)
        highest[i] = 0;
    highest[1] = prices[1];
    result = find(pizzaSize, prices, highest);
    return result;
}