#include "header.h"
int subtract(int x, int y) 
{ 
    while (y != 0) 
    {
        int borrow = (~x) & y; 
        x = x ^ y; 
        y = borrow << 1; 
    } 
    return x; 
}

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
        parkingRow &= (parkingRow - 1);
        count = add(count, i);
    }
    return count;
}

int carPosition(unsigned int parkingRow)
{
    int count = 0;

    if(occupiedPlaces(parkingRow) > 1 || occupiedPlaces(parkingRow) < 1 )
        return -1;
    else
        while(parkingRow)
        {
            parkingRow = parkingRow >> 1;
            count = add(count, 1);
        }
    return subtract(count, 1);
}
