#ifndef NULL
#define NULL ((void *)0)
#endif

#include "List.h"
#include "Tree.h"

#define ASCII_SIZE 256

int* setPriorityArray(FILE* file)
{
    int* priority = (int*) malloc((sizeof(int)*ASCII_SIZE));
    for (size_t i = 0; i < ASCII_SIZE; i++)
    {
        priority[i] = 0;
    }
    while (!feof(file))
    {
        char c = fgetc(file);
        priority[c]++;
    }
    return priority;
};

LIST* createListOfPriority(int* array)
{
    LIST* list = createList();
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (0 < array[i])
        {
            addHead(list, createNewTree(i, array[i]));
        }        
    }
    quickSort(list);
    return list;
};

TREE* createTreeBasedOnPriority(LIST* list)
{
    TREE* root;
    while (1 < list->size)
    {
        if (2 <= list->size)
        {
            root = createNewTree(0, 0);
            insertOnTree(root, list->head->tree, list->head->prox->tree);
            removeHead(list);
            removeHead(list);
            addTail(list, root);
            quickSort(list);
        }
    }
    return root;
}

void printTree(TREE* tree, int level)
{
    if (tree == NULL)
    {
        return;
    }
    level += 10;

    printTree(tree->right, level);

    printf("\n");
    for (int i = 10; i < level; i++) {
        printf(" ");
    }
    printf("(%i %c)", tree->priority, tree->varchar);

    printTree(tree->left, level);
};

int main(void)
{
    FILE* fread = fopen("./text.txt", "r");
    int* priority = setPriorityArray(fread);
    LIST* list = createListOfPriority(priority);
    TREE* tree = createTreeBasedOnPriority(list);
    printTree(tree, 0);
    
    fclose(fread);
}