#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.c";
#define NULL ((void *)0)
#define COLUMNS 53

//hash table
typedef struct{
    struct SList* head;
    struct SList* tail;
    int size;
}HASHTABLE;
//columns
typedef struct SCol
{
    struct SCol* prev;
    int * SList;
    struct SCol* prox;
}COL;