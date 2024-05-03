#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

//struct
//node
typedef struct SNode
{
    int id;
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
    printf("\nUnderflow: list is NULL\n");
}
void getPivotErr()
{
    printf("\npivot is the last one or list empty\n");
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
/*
pivot is a reference to where place or remove
*/

//add node on list
int addNode(LIST* list, int id, NODE* pivot)
{
    NODE* node = createNode();
    if (node != NULL)
    {
        node->id = id;
        if(pivot == NULL)
        {
            if(list->size == 0)
            {
                list->tail = node;
            }
            node->prox = list->head;
            list->head = node;
        }else
        {
            if (pivot->prox == NULL)
            {
                list->tail = node;
            }
            node->prox = pivot->prox;
            pivot->prox = node;
        }
        list->size++;
        return 1;
    }else
    {
        getOverflowErr();
        return 0;
    }
    
}
//other add
    //add head
    void addHead(LIST* list, int id)
    {
        addNode(list, id, NULL);
    }
    //add tail
    void addTail(LIST* list, int id)
    {
        addNode(list, id, list->tail);
    }

//to find some node using id
NODE* findNode(LIST* list, int id)
{
    NODE* node;
    if (list->head != NULL)
    {
        node = list->head;
        int i = 1;
        while (i == 1)
        {
            if (node->id == id)
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
//to find the prev of the node
NODE* findNodePrev(LIST* list, int id)
{
    NODE* node;
    NODE* prev = NULL;
    if (list->head != NULL)
    {
        node = list->head;
        int i = 1;
        while (i == 1)
        {
            if (node->id == id)
            {
                i=0;
            }else if(node->prox == NULL)
            {
                prev = NULL;
                i=0;
            }else
            {
                prev = node;
                node = node->prox;
            }
        }      
    }else
    {
        node = NULL;
    }
    return prev;
}
///remove node on list
//in case of receiving parameter from find Pivot, if find Pivot don't find the pivot, will return NULL thats mean remove from head
int removeNode(LIST* list, NODE* pivot)
{
    if(list->size == 0){
        getUnderflowErr();
        return 0;
    }else
    {
        NODE* node;
        if(pivot == NULL)
        {
            node = list->head;
            list->head = node->prox;
            if(list->head == NULL)
            {
                list->tail = NULL;
            }
            free(node);
            list->size--;
            return 1;
        }else
        {
            if(pivot->prox == NULL)
            {
                getPivotErr();
                return 0;
            }else
            {
                node = pivot->prox;
                pivot->prox = node->prox;
                if(pivot->prox == NULL)
                {
                    list->tail = pivot;
                }
                free(node);
                list->size--;
                return 1;
            }
        }
    }
}
//other remove
    //remove head
    void removeHead(LIST* list)
    {
        removeNode(list, NULL);
    }
//print all values
int runList(LIST* list)
{
    if (list->head != NULL)
    {
        NODE* node = list->head;
        while (node != NULL)
        {
            printf("%i \n", node->id);
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