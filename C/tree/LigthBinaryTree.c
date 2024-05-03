#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    int id;
}TREE;

TREE* createNewTree(int id);
void freeTree(TREE* root);
TREE* findRoot(TREE* tree);
int insertOnRightSizeTree(TREE* root, int id);
int insertOnLeftSizeTree(TREE* root, int id);
int insertOnTree(TREE** adrs, TREE* root, int id);
int transplantTree(TREE* root, TREE* tree, TREE* src);
TREE* searchOnTree(TREE* root, int id);
TREE* searchLinearOnTree(TREE* root, int id);
int removeOnTree(TREE* root, TREE* tree);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);


int main(void)
{
    TREE* tree = NULL;
    int op = -1, id = 0;
    while (op != 0)
    {
        if (NULL != tree)
        {
            printf("-------------------------------\n 1 insert \n 2 print in order \n 3 print post order \n 4 print pre order \n 5 max id \n 6 mim id \n 7 remove \n 0 exit \n-------------------------------\n");
            scanf("%i", &op);
            if (op == 1)
            {
                printf("set tree id:");
                scanf("%i", &id);
                insertOnTree(&tree, tree, id);

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
                printf("%i\n", maxTree(tree)->id);
            }else if (op == 6)
            {
                printf("%i\n", minTree(tree)->id);
            }else if (op == 7)
            {
                printf("value to be removed:\n");
                scanf("%i", &id);
                removeOnTree(tree, searchOnTree(tree, id));
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
            scanf("%i", &id);
            insertOnTree(&tree, tree, id);
        }
    }
    freeTree(tree);
    return 0;
};

TREE* createNewTree(int id)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (tree != NULL)
    {
        tree->left = NULL;
        tree->right = NULL;
        tree->id = id;
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
        printf("%i,", root->id);
        printInOrderTree(root->right);
    }
    return 0;
};

int printPreOrderTree(TREE* root)
{
    if (root != NULL)
    {
        printf("%i,", root->id);
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
        printf("%i,", root->id);
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

int insertOnRightSizeTree(TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
    if (newtree != NULL)
    {
        root->right = newtree;
        return 1;
    }else
    {
        return 0;
    }
};

int insertOnLeftSizeTree(TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
    if (newtree != NULL)
    {
        root->left = newtree;
        return 1;
    }else
    {
        return 0;
    }
};

int insertOnTree(TREE** adrs, TREE* root, int id)
{
    if (root != NULL)
    {   
        if (id > root->id)
        {
            if (NULL != root->right)
            {
                insertOnTree(adrs, root->right, id);
            }else
            {
                insertOnRightSizeTree(root, id);
            }
        }else if(id < root->id)
        {
            if (NULL != root->left)
            {
                insertOnTree(adrs, root->left, id);
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
        (*adrs) = createNewTree(id);
    }
    return 1;
};

TREE* searchOnTree(TREE* root, int id)
{
    if(id == root->id)
    {
        return root;
    }else
    {        
        if (NULL != root->left && id < root->id)
        {
            return searchOnTree(root->left, id);
        }else if(NULL != root->right && id > root->id)
        {
            return searchOnTree(root->right,id);
        }
    }
};

TREE* searchLinearOnTree(TREE* root, int id)
{
    while (id != root->id && NULL != root)
    {
        if (NULL != root->left && id < root->id)
        {
            root = root->left;
        }else if(NULL != root->right && id > root->id)
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
        }else if (root->id < tree->id)
        {
            return findParent(root->left, tree);
        }else if (root->id > tree->id)
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