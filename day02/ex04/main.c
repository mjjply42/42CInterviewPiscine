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

// Function used for the test
// Don't go further :)

void printUtensils(unsigned char *utensils, int n)
{
	int order = 1;
	printf("{ ");
	for (int i = 0; i < n; i++){
		printf("%d%s", utensils[i], (i + 1 < n) ? ", " : " ");
		if (i >= 1 && utensils[i - 1] > utensils[i])
			order = 0;
	}
	printf("} (%s)\n", (order) ? "sorted" : "not sorted");
}


#define NUMBER_OF_USTENSILS 15

unsigned char *genRandomUstensils(int *n)
{
	unsigned char *utensils;

	srand(time(NULL));
	if ((*n) <= 0 || (*n) > 1000000000){
		(*n) = rand() % 1000000 + 1; //generating int between 1 and 1.000.000
	}
	utensils = malloc(sizeof(unsigned char) * (*n));
	for (int i = 0; i < (*n); i++){
		utensils[i] = rand() % NUMBER_OF_USTENSILS + 1;
	}
	return (utensils);
}

int main(void)
{
	unsigned char *utensils;
	int n = 1000;
	utensils = genRandomUstensils(&n); //if param == 0, the length of the list will be random between 1 and 1 million

	/*-------------------
	launch your test here
	--------------------*/
	printUtensils(utensils, n);

	//printf("sorting using count sort...\n");
	countSort(utensils, n);

	printUtensils(utensils, n);

	return (0);
}
