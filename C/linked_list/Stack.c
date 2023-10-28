#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

//struct
//node
typedef struct SNode
{
    struct SNode* prev;
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
    printf("\nUnderflow: stack is NULL\n");
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
        return node;
    }else
    {
        return NULL;
    }
}

//Node operations
//add node on list
int addNode(LIST* list, int info)
{
    NODE* node = createNode();
    if (node != NULL)
    {
        node->info = info;
        if(list->tail == NULL)
        {
            node->prox = list->tail;
            node->prev = list->head;
            list->head = node;
            list->tail = node;
        }else
        {
            node->prev = list->tail;
            node->prox = list->tail->prox;
            list->tail->prox = node;
            list->tail = node;
        }
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
    if (list->head != NULL && node != NULL)
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
        if (node == NULL)
        {
            getOverflowErr();
        }
        node = NULL;
    }
    return node;
}
///remove node on list
int removeNode(LIST* list)
{
    if(list->size == 0){
        getUnderflowErr();
        return 0;
    }else
    {
        NODE* node;
        node = list->tail;
        if (node->prev != NULL)
        {
            node->prev->prox = NULL;
            list->tail = node->prev;
            
        }else
        {
            list->tail = NULL;
            list->head = NULL;
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
//print all values end to start
int runBackList(LIST* list)
{
    if (list->tail != NULL)
    {
        NODE* node = list->tail;
        while (node != NULL)
        {
            printf("%i \n", node->info);
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

int main()
{
    LIST* list = createList();
    int i = 0;
    while(i != -1)
    {
        printf("---------------------------------------\n");
        printf("1.Adiciona valor \n2.Remove valor \n3.Ver lista \n4.Ver lista ao contrario \n-1.Sair \n");
        scanf("%i",&i);
        if (i == 1)
        {
            int item;
            printf("dados do item da lista:");
            scanf(" %i", &item);
            addNode(list, item);
        }else if(i == 2)
        {
            removeNode(list);
        }else if(i == 3)
        {
            runList(list);
        }else if(i == 4)
        {
            runBackList(list);
        }else if(i == -1)
        {
            printf("saindo...\n");
        }
    }
    freeList(list);
    printf("lista limpa");
    return 0;
}
