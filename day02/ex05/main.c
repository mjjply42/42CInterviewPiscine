#include "header.h"

int     search(int *arr,int key,int low,int high)
{

        int mid = (low + high) / 2;
        if(low > high)
                return -1;
        if(arr[mid] == key && arr[mid - 1] != key)
                return mid;
        if(arr[low] <= arr[mid])
                if (arr[low] <= key && arr[mid] >= key) 
                        return search(arr,key,low,mid-1);
                else                 
                        return search(arr,key,mid+1,high);
        else    
                if(arr[mid] <= key && arr[high] >= key) 
                        return search(arr,key,mid+1,high);
                else
                        return search(arr,key,low,mid-1);
}

int searchShifted(int *rocks, int length, int value)
{
    int index = search(rocks,value,0,length-1);
    return index;
}
int     main()
{
    int arr[] = {6,6,7,7,7,1,1,2,2,3,3,3,3,4,4,5,5,5};
    int check = searchShifted(arr,16,12);
    printf("Index is at: %i\n", check);
    

    return 1;
}