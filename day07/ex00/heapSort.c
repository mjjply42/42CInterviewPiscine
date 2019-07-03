#include "header.h"

struct  s_node
{
    int value;
    char *name;
    struct s_node *left;
    struct s_node *right;
};

void    swap(struct s_art *a, struct s_art *b)
{
    struct s_art tmp = *a;
    *a = *b;
    *b = tmp;
}

void    heapify(struct s_art **arts, int index, int size)
{
    int largest = index;
    int left = (2*index + 1);
    int right = (2*index + 2);

    if(left < size && strcmp(arts[left]->name, arts[largest]->name) > 0)
        largest = left;
    if(right < size && strcmp(arts[right]->name, arts[largest]->name) > 0)
        largest = right;
    if(largest != index)
    {
        swap(arts[index], arts[largest]);
        heapify(arts, largest, size);
    }
}
void    heapSort(struct s_art **masterpiece, int n)
{
    for(int i = n/2 -1; i >= 0; i--)
        heapify(masterpiece, i, n);
    for (int i=n-1; i>=0; i--) 
    { 
        swap(masterpiece[0], masterpiece[i]);
        heapify(masterpiece, 0, i); 
    } 
}