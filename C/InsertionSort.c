
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int * array, int size)
{
    int i, aux, j;
    for (i = 1; i < size; i++) {
        //aux is a key
        aux = array[i];
        //defines where starts
        j = i-1;
        //while j > 0 & array > aux(key)
            while (j >= 0 && array[j] > aux) {
                //makes all numbers greater than aux go up
                array[j+1] = array[j];
                //regresses to the previous index
                j = j-1;
            }
        //Put the key where the code stopped
        array[j+1] = aux;
    }
}