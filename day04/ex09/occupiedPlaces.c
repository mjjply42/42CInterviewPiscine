#include "header.h"

int     add(int num, int num2)
{
    if (!num)
        return num2;
    else
        return add((num & num2) << 1, num ^ num2);
}

int occupiedPlaces(unsigned int parkingRow)
{
    int count = 0;
    int i = 1;
    while(parkingRow)
    {
        parkingRow &= (subtract(parkingRow, 1));
        count = add(count, i);
    }
    return count;
}