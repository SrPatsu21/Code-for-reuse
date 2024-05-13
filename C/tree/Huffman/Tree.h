#ifndef TREEHUFFMAN_H
#define TREEHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#define NULL 0 //((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    char varchar;
}TREE;

TREE* createNewTree(int id);
void freeTree(TREE* root);
TREE* findParent(TREE* root, TREE* tree);
int insertOnRightSizeTree(TREE* root, int id);
int insertOnLeftSizeTree(TREE* root, int id);
int insertOnTree(TREE* root, int id);
int transplantTree(TREE* root, TREE* tree);
int reInplantTree(TREE* main_root, TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int id);
TREE* searchLinearOnTree(TREE* root, int id);
int removeOnTree(TREE** root, TREE* tree, TREE* tree_root);
int removeOnTreeByid(TREE** root, int id);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);

TREE* createNewTree(char varchar)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (NULL != tree)
    {
        tree->left = NULL;
        tree->right = NULL;
        tree->varchar = varchar;
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

//dont know how to do
int insertOnTree(TREE* root, int id)
{
    if (root != NULL)
    {   
        if (id > root->id)
        {
            if (NULL != root->right)
            {
                insertOnTree(root->right, id);
            }else
            {
                insertOnRightSizeTree(root, id);
            }
        }else if(id < root->id)
        {
            if (NULL != root->left)
            {
                insertOnTree(root->left, id);
            }else
            {
                insertOnLeftSizeTree(root, id);
            }
        }else
        {
            return 0;
        }
    }else
    {
        printf("null root\n");
        return 0;
    }
    return 1;
};

TREE* searchOnTree(TREE* root, char** c, int* i)
{
    if(NULL == root->left & NULL == root->right)
    {
        return root;
    }else
    {        
        if (*c[*i] == '1')
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