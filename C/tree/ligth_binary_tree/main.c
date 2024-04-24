#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    int info;
}TREE;

TREE* createNewTree(int info);
void freeTree(TREE* root);
TREE* findRoot(TREE* tree);
int insertOnRightSizeTree(TREE* root, int info);
int insertOnLeftSizeTree(TREE* root, int info);
int insertOnTree(TREE** adrs, TREE* root, int info);
int transplantTree(TREE* root, TREE* tree, TREE* src);
TREE* searchOnTree(TREE* root, int info);
TREE* searchLinearOnTree(TREE* root, int info);
int removeOnTree(TREE* root, TREE* tree);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);


int main(void)
{
    TREE* tree = NULL;
    int op = -1, info = 0;
    while (op != 0)
    {
        if (NULL != tree)
        {
            printf("-------------------------------\n 1 insert \n 2 print in order \n 3 print post order \n 4 print pre order \n 5 max info \n 6 mim info \n 7 remove \n 0 exit \n-------------------------------\n");
            scanf("%i", &op);
            if (op == 1)
            {
                printf("set tree info:");
                scanf("%i", &info);
                insertOnTree(&tree, tree, info);

            }else if (op == 2)
            {
                printInOrderTree(tree);
                printf("\n");
            }else if (op == 3)
            {
                printPostOrderTree(tree);
                printf("\n");
            }else if (op == 4)
            {
                printPreOrderTree(tree);
                printf("\n");
            }else if (op == 5)
            {
                printf("%i\n", maxTree(tree)->info);
            }else if (op == 6)
            {
                printf("%i\n", minTree(tree)->info);
            }else if (op == 7)
            {
                printf("value to be removed:\n");
                scanf("%i", &info);
                removeOnTree(tree, searchOnTree(tree, info));
            }else if (op == 0)
            {
                printf("exiting...\n");
            }else 
            {
                printf("invalid\n");
            }
        }else
        {
            printf("Tree null, init value:\n");
            scanf("%i", &info);
            insertOnTree(&tree, tree, info);
        }
    }
    freeTree(tree);
    return 0;
};

TREE* createNewTree(int info)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (tree != NULL)
    {
        tree->left = NULL;
        tree->right = NULL;
        tree->info = info;
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

int printInOrderTree(TREE* root)
{
    if (root != NULL) 
    {
        printInOrderTree(root->left);
        printf("%i,", root->info);
        printInOrderTree(root->right);
    }
    return 0;
};

int printPreOrderTree(TREE* root)
{
    if (root != NULL)
    {
        printf("%i,", root->info);
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
        printf("%i,", root->info);
    }
    return 0;
};

TREE* maxTree(TREE* tree)
{
    if (NULL != tree->right)
    {
        return maxTree(tree->right);
    }else
    {
        return tree;
    }
};

TREE* minTree(TREE* tree)
{
    if (NULL != tree->left)
    {
        return minTree(tree->left);
    }else
    {
        return tree;
    }
};

int insertOnRightSizeTree(TREE* root, int info)
{
    TREE* newtree = createNewTree(info);
    if (newtree != NULL)
    {
        root->right = newtree;
        return 1;
    }else
    {
        return 0;
    }
};

int insertOnLeftSizeTree(TREE* root, int info)
{
    TREE* newtree = createNewTree(info);
    if (newtree != NULL)
    {
        root->left = newtree;
        return 1;
    }else
    {
        return 0;
    }
};

int insertOnTree(TREE** adrs, TREE* root, int info)
{
    if (root != NULL)
    {   
        if (info > root->info)
        {
            if (NULL != root->right)
            {
                insertOnTree(adrs, root->right, info);
            }else
            {
                insertOnRightSizeTree(root, info);
            }
        }else if(info < root->info)
        {
            if (NULL != root->left)
            {
                insertOnTree(adrs, root->left, info);
            }else
            {
                insertOnLeftSizeTree(root, info);
            }
        }else
        {
            return 0;
        }
    }else
    {
        (*adrs) = createNewTree(info);
    }
    return 1;
};

TREE* searchOnTree(TREE* root, int info)
{
    if(info == root->info)
    {
        return root;
    }else
    {        
        if (NULL != root->left && info < root->info)
        {
            return searchOnTree(root->left, info);
        }else if(NULL != root->right && info > root->info)
        {
            return searchOnTree(root->right,info);
        }
    }
};

TREE* searchLinearOnTree(TREE* root, int info)
{
    while (info != root->info && NULL != root)
    {
        if (NULL != root->left && info < root->info)
        {
            root = root->left;
        }else if(NULL != root->right && info > root->info)
        {
            root = root->right;
        }else{
            root = NULL;
        }
    }
    return root;
};

TREE* findParent(TREE* root, TREE* tree)
{
    if (root != NULL)
    {
        if (root->right == tree || root->left == tree)
        {
            return root;
        }else if (root->info < tree->info)
        {
            return findParent(root->left, tree);
        }else if (root->info > tree->info)
        {
            return findParent(root->right, tree);
        }
    }
    return NULL;
};

int transplantTree(TREE* root, TREE* tree, TREE* src) 
{
    TREE* parent = findParent(root, tree);
    if (NULL == parent)
    {
        root = src;
    }
    else if (tree == parent->left) 
    {
        parent->left = src;
    } else 
    {
        parent->right = src;
    }
    return 1;
}

int removeOnTree(TREE* root, TREE* tree) 
{
    TREE* aux;
    if (NULL == tree->left) 
    {
        transplantTree(root, tree, tree->right);
    } else if (NULL == tree->right) 
    {
        transplantTree(root, tree, tree->left);
    } else
     {
        aux = minTree(tree->right);
        if (aux != tree->right)
        {
            transplantTree(root, aux, aux->right);
            aux->right = tree->right;
        }
        transplantTree(root, tree, aux);
        aux->left = tree->left;
        free(tree);
    }
    return 1;
}