#ifndef NULL
#define NULL 0
#endif

#ifndef TREEHUFFMAN_H
#define TREEHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    char varchar;
    int priority;
}TREE;

TREE* createNewTree(char varchar, int priority);
void freeTree(TREE* root);
int insertOnTree(TREE* root, TREE* newtree1, TREE* newtree2);
TREE* searchOnTree(TREE* root, char* c, int* i);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* minTree(TREE* tree);

TREE* createNewTree(char varchar, int priority)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (NULL != tree)
    {
        tree->left = NULL;
        tree->right = NULL;
        tree->varchar = varchar;
        tree->priority = priority;
    }
    return tree;
};

void freeTree(TREE* root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
};

int insertOnTree(TREE* root, TREE* tree1, TREE* tree2)
{
    if (root != NULL)
    {
        if (tree1->priority > tree2->priority)
        {
            root->left = tree2;
            root->right = tree1;
        }else
        {
            root->left = tree1;
            root->right = tree2;
        }
        root->priority = (tree1->priority + tree2->priority);
    }else
    {
        printf("\nnull root\n");
        return 0;
    }
    return 1;
};

TREE* searchOnTree(TREE* root, char* c, int* i)
{
    if(NULL == root->left & NULL == root->right)
    {
        return root;
    }else
    {        
        if (c[*i] == '1')
        {
            *i+1;
            return searchOnTree(root->right, c, i);
        }else
        {
            *i+1;
            return searchOnTree(root->left, c, i);
        }
    }
};

int printInOrderTree(TREE* root)
{
    if (root != NULL) 
    {
        printInOrderTree(root->left);
        printf("%i,", root->varchar);
        printInOrderTree(root->right);
    }
    return 0;
};

int printPreOrderTree(TREE* root)
{
    if (root != NULL)
    {
        printf("%i,", root->varchar);
        printPreOrderTree(root->left);
        printPreOrderTree(root->right);
    }
    return 0;
};

int printPostOrderTree(TREE* root)
{
    if (root != NULL)
    {
        printPostOrderTree(root->left);
        printPostOrderTree(root->right);
        printf("%i,", root->varchar);
    }
    return 0;
};

#endif