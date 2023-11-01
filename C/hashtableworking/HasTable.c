#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.c"
#define COLUMNS 53
#define FOLDER "nomes.txt"

//columns
typedef struct SCol
{
    struct SCol* prev;
    struct SList* list;
    int key;
    struct SCol* prox;
}COL;
//hash table
typedef struct{
    struct SCol* head;
    struct SCol* tail;
    int size;
}HASHTABLE;
//err
void getInitializationErr()
{
    printf("\nIt is already defined\n");
}
//create hashtable
HASHTABLE* CreateTableHash()
{
    HASHTABLE* hash = (HASHTABLE*) malloc(sizeof(HASHTABLE*));
    if (hash != NULL)
    {
        hash->head = NULL;
        hash->tail = NULL;
        hash->size = 0;
        return hash;
    }else
    {
        return NULL;
    }
}
//creating columns
COL* createCol(int key)
{
    COL* col =(struct SCol*) malloc(sizeof(COL));
    if (col != NULL)
    {
        col->prev= NULL;
        col->prox = NULL;
        col->list = createList();
        col->key = key;
        return col;
    }else
    {
        return NULL;
    }
}
//add columns
int addColumns(HASHTABLE* hash, int key)
{
    COL* col = createCol(key);
    if (col != NULL)
    {
        if(hash->tail == NULL)
        {
            col->prox = hash->tail;
            col->prev = hash->head;
            hash->head = col;
            hash->tail = col;
        }else
        {
            col->prev = hash->tail;
            col->prox = hash->tail->prox;
            hash->tail->prox = col;
            hash->tail = col;
        }
        hash->size++;
        return 1;
    }else
    {
        getOverflowErr();
        return 0;
    }
}
//auto create hash table
int autoDefineHashTable(HASHTABLE* hash, int Columns)
{
    if (hash->size == 0 && hash->head == NULL && hash->tail == NULL)
    {
        for (int i = 0; i < Columns; i++)
        {
            addColumns(hash, i);
        }
        return 1;
    }else
    {
        getInitializationErr();
        return 0;
    }
}
//what key will be
int hashing(HASHTABLE* hash, char name [NAME_SIZE])
{
    int key = 0;
    for (int i = 0; i < sizeof(*name)/sizeof(char); i++)
    {
                key = (31 * key + name[i]) % hash->size+1;
    }
    return key;
}
//find the key on hash table
COL* findColumn(HASHTABLE* hash, int key)
{
    COL* col = hash->head;
    while (col->key != key && col != NULL)
    {
        col = col->prox;
    }
    return col;
}
//add the name on the correct column
int addOnColumn(COL* col, char name [NAME_SIZE])
{
    return addTail(col->list, name);
}
//read the file
FILE* loadingData(char name[])
{
    FILE* fptr = fopen(name, "r");
    return fptr;
}
void printFiles(FILE* fptr){
    char myString[NAME_SIZE];
    while(fgets(myString, 7, fptr)) {
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
    FILE* fptr = loadingData(FOLDER);
    printFiles(fptr);
    //sort
    //view

    fclose(fptr);
}