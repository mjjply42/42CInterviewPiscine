#include "header.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (struct s_art **arr, int low, int high)
{
    int				i;
	int				j;
	struct s_art	*pivot;
	struct s_art	*tmp;

	i = low;
	j = high;
	pivot = arr[low];
	while (1)
	{
		while (strcmp(arr[i]->name, pivot->name) < 0)
			i += 1;
		while (strcmp(arr[j]->name, pivot->name) > 0)
			j -= 1;
		if (i < j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			if (strcmp(arr[i]->name, arr[j]->name) == 0)
				j -= 1;
		}
		else
			break;
	}
	return (j);
}

void quickSort(struct s_art **arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void    sortArts(struct s_art **arts)
{
    quickSort(arts, 0, getSize(arts) - 1);
}

