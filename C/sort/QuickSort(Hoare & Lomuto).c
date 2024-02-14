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
//find the pivot
int getPivotPos(int start, int end)
{
    return ((int) (start+end/2));
    //if you want Lomuto's version
    //return end;
}

//the principal function
//start is the initial position 0
//end is the size of the array -1
void quickSort(int* array, int start, int end) 
{
    int i, j, pivot;

    i = start;
    j = end;
    pivot = array[getPivotPos(start, end)];    

    //if i > j means that i passed the j pos
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }

        //if i <= j switch
        if (i <= j)
        {
            swap(array, i, j);
            i++;
            j--;
        }
    }
    //call int the left side of pivot
    if (start < j)
    {
        quickSort(array, start, j);
    }
    //call int the right side of pivot
    else if (i < end)
    {
        quickSort(array, i, end);
    }
}