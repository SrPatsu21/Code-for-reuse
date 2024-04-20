#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    struct Tree* root;
    int info;
}TREE;

TREE* createNewTree(int info);
void freeTree(TREE* root);
void findRoot(TREE* tree);
int insertOnRigthSizeTree(TREE* root, int info);
int insertOnLeftSizeTree(TREE* root, int info);
int insertOnTree(TREE* root, int info);
int transplantTree(TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int info);
TREE* searchLinearOnTree(TREE* root, int info);
int removeOnTree(TREE** root, int info);
int transpouseOnTree(TREE* tree);
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
                insertOnTree(tree, info);

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
                removeOnTree(&tree, info);
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
            tree = createNewTree(info);
        }
    }
    findRoot(tree);
    freeTree(tree);
    return 0;
};

TREE* createNewTree(int info)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (tree != NULL)
    {
        tree->root = NULL;
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

void findRoot(TREE* tree)
{
    if (tree->root != NULL)
    {
        tree = tree->root;
        findRoot(tree);
    }
};

int insertOnRigthSizeTree(TREE* root, int info)
{
    TREE* newtree = createNewTree(info);
    if (newtree != NULL)
    {
        root->right = newtree;
        root->right->root = root;
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
        root->left->root = root;
        return 1;
    }else
    {
        // err
        return 0;
    }
};

int insertOnTree(TREE* root, int info)
{
    if (info > root->info)
    {
        if (NULL != root->right)
        {
            insertOnTree(root->right, info);
        }else
        {
            insertOnRigthSizeTree(root, info);
        }
    }else if(info < root->info)
    {
        if (NULL != root->left)
        {
            insertOnTree(root->left, info);
        }else
        {
            insertOnLeftSizeTree(root, info);
        }
    }else
    {
        return 0;
    }
    return 1;
};

int transplantTree(TREE* root, TREE* tree)
{
    if (tree->info > root->info)
    {
        if (NULL != root->right)
        {
            transplantTree(root->right, tree);
        }else
        {
            root->right = tree;
        }
    }else if(tree->info < root->info)
    {
        if (NULL != root->left)
        {
            transplantTree(root->left, tree);
        }else
        {
            root->left = tree;
        }
    }else
    {
        return 0;
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

int removeOnTree(TREE** root, int info)
{
    TREE* t = searchOnTree(*root, info);
    
    if (NULL != t)
    {
        if (NULL != t->root)
        {
            TREE* aux = t->root;
            if (aux->left == t)
            {
                if (NULL != t->right)
                {
                    t->right->root = aux;
                    aux->left = t->right;
                    if (NULL != t->left)
                    {
                        transplantTree(t->right, t->left);
                    }
                }else if(NULL != t->left)
                {
                    t->left->root = aux;
                    aux->left = t->left;
                }else
                {
                    aux->left = NULL;
                }
                t->info = 0;
                free(t);
                return 1;
            }else if (aux->right == t)
            {
                if (NULL != t->right)
                {
                    t->right->root = aux;
                    aux->right = t->right;
                    if (NULL != t->left)
                    {
                        transplantTree(t->right, t->left);
                    }
                }else if(NULL != t->left)
                {
                    t->left->root = aux;
                    aux->right = t->left;
                }else
                {
                    aux->right = NULL;
                }
                t->info = 0;
                free(t);
                return 1;
            }
        }else
        {
            if (NULL != t->right)
                {
                    *root = t->right;
                    t->right->root = NULL;
                    if (NULL != t->left)
                    {
                        transplantTree(t->right, t->left);
                    }
                }else if(NULL != t->left)
                {
                    *root = t->left;
                    t->left->root = NULL;
                }
                t->info = 0;
                free(t);
                return 1;
        }
    }
    printf("not found");
    return 0;
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
