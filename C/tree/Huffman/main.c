#ifndef NULL
#define NULL ((void *)0)
#endif

#include "List.h"
#include "Tree.h"

#define ASCII_SIZE 256

FILE* writeFile(char* data);
int* setPriorityArray(FILE* file);

FILE* writeFile(char* data)
{
    FILE* fptr;
 
    fptr = fopen("compacted.txt", "w");
    fputs(fptr, *data);
 
    return fptr;
};

int* setPriorityArray(FILE* file)
{
    int priority [ASCII_SIZE];
    while (!feof(file))
    {
        char c = fgetc(file);
        priority[c]++;
    }
    return priority;
};

LIST* createListOfPriority()
{
    LIST* list = createList();
    for (size_t i = 0; i < ASCII_SIZE; i++)
    {
        
    }
    
};

TREE* createTreeBasedOnPriority(int priority[ASCII_SIZE])
{
    TREE* tree;
    LIST* list;
}

int main(void)
{
    FILE* fread = fopen("text.txt", "r");
    int priority[ASCII_SIZE] = setPriorityArray(fread);

    fclose(fread);
}