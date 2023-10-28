#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//switch two values in an array
void swap(int* array, int i, int j)
{
    int aux;

	aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}
void whileSort(int * array, int size)
{
    int i = 1;
    //run the array
    while(i < size) {
        if (i!=0) 
        {
            if (array[i-1] > array[i]) {
                swap(array, i, i-1);
                    i-=2;
            }
        }
        i++;
    }
}