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

void setCodifyTable(char table[ASCII_SIZE][(ASCII_SIZE/2)], TREE* tree, int i, char c[(ASCII_SIZE/2)])
{
    if (tree != NULL)
    {
        if (tree->right == NULL && tree->left == NULL)
        {
            for (int j = 0; j < (ASCII_SIZE/2); j++)
            {
                table[((int) tree->varchar)][j] = c[j];
            }
        }else
        {
            i++;
            c[i] = 0;
            setCodifyTable(table, tree->left, i, c);
            c[i] = 1;
            setCodifyTable(table, tree->right, i, c);
        }
    }
};

int main(void)
{
    FILE* fread = fopen("./text.txt", "r");
    int* priority = setPriorityArray(fread);
    LIST* list = createListOfPriority(priority);
    TREE* tree = createTreeBasedOnPriority(list);
    printTree(tree, 0);
    //set all as \0
    char table[ASCII_SIZE][(ASCII_SIZE/2)];
    //set all as \0
    char c[(ASCII_SIZE/2)];

    setCodifyTable(table, tree, -1, c);
    
    fclose(fread);
}