#include <stdio.h>
#include <stdlib.h>

FILE* loadingData(char name[])
{
    FILE* fptr = fopen("nomes.txt", "r");
    return fptr;
}
void printFiles(FILE* fptr){
    char myString[15];
    while(1) {
        fgets(myString, 1, fptr);
        printf("%s", myString);
    }
}

void main()
{
    //init
    // int columns = COLUMNS;
    // HASHTABLE* hash = CreateTableHash(columns);
    // autoDefineHashTable(hash, columns);
    //operations
    FILE* fptr = loadingData("nomes.txt");
    char myString[15];
    do{
        printf(" %s", myString);
    }while(fgets(myString, 10, fptr));
    printf("a");
    printFiles(fptr);
    //sort
    //view

    fclose(fptr);
}