#ifndef NULL
#define NULL 0
#endif

#ifndef LISTHUFFMAN_H
#define LISTHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//struct
//node
typedef struct SNode
{
    struct SNode* prev;
    TREE* tree;
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
        node->prev= NULL;
        node->prox = NULL;
        node->tree = NULL;
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
int addNode(LIST* list, TREE* tree, NODE* pivot)
{
    NODE* node = createNode();
    if (node != NULL)
    {
        node->tree = tree;
            if(pivot == NULL)
            {
                if(list->size == 0)
                {
                    list->tail = node;
                }else
                {
                    list->head->prev = node;
                }
                node->prox = list->head;
                list->head = node;
            }else
            {
                node->prev = pivot;
                node->prox = pivot->prox;
                if (pivot->prox == NULL)
                {
                    list->tail = node;
                }else
                {
                    node->prox->prev = node;
                }
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
    void addHead(LIST* list, TREE* tree)
    {
        addNode(list, tree, NULL);
    }
    //add tail
    void addTail(LIST* list, TREE* tree)
    {
        addNode(list, tree, list->tail);
    }

//to find some node using id
NODE* findNode(LIST* list, TREE* tree)
{
    NODE* node;
    if (list->head != NULL && node != NULL)
    {
        node = list->head;
        int i = 1;
        while (i == 1)
        {
            if (node->tree == tree)
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
        if (node == NULL)
        {
            getOverflowErr();
        }
        node = NULL;
    }
    return node;
}
//to find the prev of the node
NODE* findNodePrev(LIST* list, TREE* tree)
{
    NODE* node = findNode(list, tree);
    if (node == NULL)
    {
        return NULL;
    }else{
        return node->prev;
    }
}
//remove node on list
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
            if(node->prox == NULL)
            {
                list->tail = NULL;
            }else
            {
                node->prox->prev = NULL;
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
                if(node->prox == NULL)
                {
                    list->tail = pivot;
                }else
                {
                    node->prox->prev = pivot;
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
    //remove tail
    void removeTail(LIST* list)
    {
        removeNode(list, list->tail->prev);
    }
//print all values
int runList(LIST* list)
{
    if (list->head != NULL)
    {
        NODE* node = list->head;
        while (node != NULL)
        {
            printf("%i %c \n", node->tree->priority, node->tree->varchar);
                node = node->prox;
        }
    }else
    {
        getUnderflowErr();
    }
}
//print all values end to start
int runBackList(LIST* list)
{
    if (list->tail != NULL)
    {
        NODE* node = list->tail;
        while (node != NULL)
        {
            printf("%i %c \n", node->tree->priority, node->tree->varchar);
                node = node->prev;
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

/*
*   sort
*/

void swap ( TREE** tree1, TREE** tree2 )
{
    TREE* t = *tree1;
    *tree1 = *tree2;
    *tree2 = t; 
}

NODE* partition(NODE* nstart, NODE* nend)
{
	TREE* x = nend->tree;
	NODE *i = nstart->prev;

	for (NODE* j = nstart; j != nend; j = j->prox)
	{
		if (j->tree->priority <= x->priority)
		{
			if(i == NULL)
            {
                i = nstart;
            }
            else
            { 
                i = i->prox;
            }

			swap(&(i->tree), &(j->tree));
		}
	}
    if(i == NULL)
    {
        i = nstart;
    }else
    {
        i = i->prox;
    }
	swap(&(i->tree), &(nend->tree));
	return i;
}

void _quickSort(NODE* nstart, NODE* nend)
{
	if (nend != NULL && nstart != nend && nstart != nend->prox)
	{
		NODE* p = partition(nstart, nend);
		_quickSort(nstart, p->prev);
		_quickSort(p->prox, nend);
	}
}

// The main function to sort a linked list.
// It mainly calls _quickSort()
void quickSort(LIST* list)
{
	_quickSort(list->head, list->tail);
}

#endif