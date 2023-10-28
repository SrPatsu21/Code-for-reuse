/*
You may use the singly linked list, controlling the input parameters the result is the same.
This is just a more efficient solution.
*/
#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

//struct
//node
typedef struct SNode
{
    int info;
    struct SNode* prox;
}NODE;
//list
typedef struct{
    struct SNode* head;
    struct SNode* tail;
    int size;
}LIST;
//errs
void getOverflowErr()
{
    printf("\nOverflow: exceeded the device's storage capacity!\n");
}
void getUnderflowErr()
{
    printf("\nUnderflow: queue is NULL\n");
}
//alloc LIST
LIST* createList()
{
    LIST * list =(LIST*) malloc(sizeof(LIST));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
//alloc node
NODE* createNode()
{
    NODE* node;
    node =(struct SNode*) malloc(sizeof(NODE));
    if (node != NULL)
    {
        node->prox = NULL;
        return node;
    }else
    {
        return NULL;
    }
}

//Node operations
//add node on queue
int addNode(LIST* list, int info)
{
    NODE* node = createNode();
    if (node != NULL)
    {
        node->info = info;

        node->prox = NULL;
        if(list->tail == NULL)
        {
            list->head = node;
        }else
        {
            list->tail->prox = node;
        }
        list->tail = node;

        list->size++;
        return 1;
    }else
    {
        getOverflowErr();
        return 0;
    }
    
}
//to find some node using info
NODE* findPivot(LIST* list, int info)
{
    NODE* node;
    if (list->head != NULL)
    {
        node = list->head;
        int i = 1;
        while (i == 1)
        {
            if (node->info == info)
            {
                i=0;
            }else if(node->prox == NULL)
            {
                node = NULL;
                i=0;
            }else
            {
                node = node->prox;
            }
        }      
    }else
    {
        node = NULL;
    }
    return node;
}
//remove node on queue
int removeNode(LIST* list)
{
    if(list->size == 0){
        getUnderflowErr();
        return 0;
    }else
    {
        NODE* node;
        node = list->head;
        list->head = node->prox;
        if(list->head == NULL)
        {
            list->tail = NULL;
        }
        free(node);
        list->size--;
        return 1;
    }
}
//print all values
int runList(LIST* list)
{
    if (list->head != NULL)
    {
        NODE* node = list->head;
        while (node != NULL)
        {
            printf("%i \n", node->info);
                node = node->prox;
        }
    }else
    {
        getUnderflowErr();
    }
}
//!important!
//clear memory 
void freeList(LIST* list)
{
    if (list->head != NULL)
    {
        NODE* node = list->head;
        while (node != NULL)
        {
            NODE* aux = node;
            node = node->prox;
            free(aux);
        }
    }
    free(list);
}