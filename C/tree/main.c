#include <stdio.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* rigth;
    struct Tree* left;
    struct Tree* root;
    int info;
}TREE;

TREE* createNewTree(int info);
void freeTree(TREE* root);
void returnToRoot(TREE* tree);
int insertOnRigthSizeTree(TREE* root, int info);
int insertOnLeftSizeTree(TREE* root, int info);
TREE inOrderTree(TREE* root);
TREE preOrderTree(TREE* root);
TREE postOrderTree(TREE* root);



int main(void)
{
    TREE* tree = createNewTree(0);
    if (tree != NULL)
    {
        int op;
        while (op != 0)
        {
            printf("1 insert \n 2 return \n 0 exit");
            if (op == 1)
            {
                // insertOnLeftSizeTree();
                // insertOnRigthSizeTree();

            }else if (op == 2)
            {
                if (tree->root == NULL)
                {
                    printf("invalid return");
                }else
                {
                    printf("valid return");
                    tree = tree->root;
                }
            }else if (op == 0)
            {
                //go out
            }else 
            {

            }
        }
    }else
    {
        printf("Unable to run");
    }
    returnToRoot(tree);
    freeTree(tree);
    return 0;
}

TREE* createNewTree(int info)
{
    TREE* tree = (TREE*) malloc(sizeof(TREE));
    if (tree != NULL)
    {
        tree->root = NULL;
        tree->left = NULL;
        tree->rigth = NULL;
        tree->info = info;
        return tree;
    }else
    {
        return NULL;
    }
};

//efficiency --
void freeTree(TREE* root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->rigth);
        free(root);
    }
};

void returnToRoot(TREE* tree)
{
    if (tree->root != NULL)
    {
        tree = tree->root;
        returnToRoot(tree);
    }
}

int insertOnRigthSizeTree(TREE* root, int info)
{
    TREE* newtree = createNewTree(info);
    if (newtree != NULL)
    {
        root->rigth = newtree;
        root->rigth->root = root;
        return 1;
    }else
    {
        // err
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
