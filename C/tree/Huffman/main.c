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
    if ('\n' != tree->varchar)
    {
        printf("(%i %c)", tree->priority, tree->varchar);
    }else
    {
        printf("(%i \\n)", tree->priority);
    }
    
    

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
            printf("\n");
        }else
        {
            i++;
            c[i] = '0';
            setCodifyTable(table, tree->left, i, c);
            c[i] = '1';
            setCodifyTable(table, tree->right, i, c);
        }
    }
};
//! make all values of char vet null
void nullVetChar(char c[(ASCII_SIZE/2)], int size)
{
    for (int i = 0; i < size; i++)
    {
        c[i] = '\0';
    }
    
};
//! make all values of char array null
void nullArrayChar(char c[ASCII_SIZE][(ASCII_SIZE/2)], int h, int l)
{
    for (int j = 0; j < h; j++)
    {    
        for (int i = 0; i < l; i++)
        {
            c[j][i] = '\0';
        }
    }
};

void printArray(char c[ASCII_SIZE][(ASCII_SIZE/2)], int h, int l)
{
    int count= 0;
    printf("\n");
    for (int j = 0; j < h; j++)
    {    
        if (3 < count)
        {
            printf("\n");
            count = 0;
        }else
        {
            count++;
        }
        printf("(%i | ", j);
        for (int i = 0; i < l; i++)
        {
            printf("%c", c[j][i]);
        }
        printf(")  ");
    }
    printf("\n");
};

int main(void)
{
    FILE* fread = fopen("./text.txt", "r");
    int* priority = setPriorityArray(fread);
    LIST* list = createListOfPriority(priority);
    TREE* tree = createTreeBasedOnPriority(list);
    printTree(tree, 0);

    char table[ASCII_SIZE][(ASCII_SIZE/2)];
    nullArrayChar(table, ASCII_SIZE, (ASCII_SIZE/2));
    char c[(ASCII_SIZE/2)];
    nullVetChar(c, (ASCII_SIZE/2));

    setCodifyTable(table, tree, -1, c);
    printArray(table, ASCII_SIZE, (ASCII_SIZE/2));

    /*
    *   close file
    */ 
    fclose(fread);
    /*
    *   free tree and list
    */
   freeTree(tree);
   freeList(list);
}