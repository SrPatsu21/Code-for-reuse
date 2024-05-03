#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    struct Tree* root;
    int id;
}TREE;

TREE* createNewTree(int id);
void freeTree(TREE* root);
TREE* findRoot(TREE* tree);
int insertOnRightSizeTree(TREE* root, int id);
int insertOnLeftSizeTree(TREE* root, int id);
int insertOnTree(TREE** adrs, TREE* root, int id);
int reInplantTree(TREE* root, TREE* tree);
int transplantTree(TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int id);
TREE* searchLinearOnTree(TREE* root, int id);
int removeOnTree(TREE** root, TREE* tree, TREE* tree_root);
int removeOnTreeByid(TREE** root, int id);
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
                removeOnTreeByid(&tree, id);
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
    tree = findRoot(tree);
    freeTree(tree);
    return 0;
};

TREE* createNewTree(int id)
{
    TREE* tree;
    tree = (struct Tree*) malloc(sizeof(TREE));
    if (tree != NULL)
    {
        tree->root = NULL;
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

TREE* findRoot(TREE* tree)
{
    if (tree->root != NULL)
    {
        tree = tree->root;
        return findRoot(tree);
    }else
    {
        return tree;
    }
};

TREE* findParent(TREE* root, TREE* tree)
{
    if (NULL != tree)
    {
        return tree->root;
    }else
    {
        return NULL;
    }
};

int insertOnRightSizeTree(TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
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

int insertOnLeftSizeTree(TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
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

int reInplantTree(TREE* root, TREE* tree)
{
    if (tree != NULL && root != NULL)
    {
        if (tree->id > root->id)
        {
            if (NULL != root->right)
            {
                reInplantTree(root->right, tree);
            }else
            {
                root->right = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return reInplantTree(findRoot(root), r) * reInplantTree(findRoot(root), l);
            }
        }else if(tree->id < root->id)
        {
            if (NULL != root->left)
            {
                reInplantTree(root->left, tree);
            }else
            {
                root->left = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return reInplantTree(findRoot(root), r) * reInplantTree(findRoot(root), l);
            }
        }else if (tree->id == root->id)
        {
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;
                return reInplantTree(findRoot(root), r) * reInplantTree(findRoot(root), l);
        }
    }else if (NULL == root)
    {
        return 0;
    }
    return 1;
};

int transplantTree(TREE* root, TREE* tree)
{
    if (tree->id > root->id)
    {
        if (NULL != root->right)
        {
            transplantTree(root->right, tree);
        }else
        {
            root->right = tree;
        }
    }else if(tree->id < root->id)
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

int removeOnTreeByid(TREE** root, int id)
{
    TREE* t = searchOnTree(*root, id);
    TREE* tree_root = findParent(*root, t);
    return removeOnTree(root, t, tree_root);
};

int removeOnTree(TREE** root, TREE* tree, TREE* tree_root)
{
    if (NULL != tree)
    {
        if (NULL != tree_root)
        {
            if (tree_root->left == tree)
            {
                if (NULL != tree->right)
                {
                    tree_root->left = tree->right;
                    if (NULL != tree->left)
                    {
                        transplantTree(tree->right, tree->left);
                    }
                }else if(NULL != tree->left)
                {
                    tree_root->left = tree->left;
                }else
                {
                    tree_root->left = NULL;
                }
                tree->id = 0;
                free(tree);
                return 1;
            }else if (tree_root->right == tree)
            {
                if (NULL != tree->right)
                {
                    tree_root->right = tree->right;
                    if (NULL != tree->left)
                    {
                        transplantTree(tree->right, tree->left);
                    }
                }else if(NULL != tree->left)
                {
                    tree_root->right = tree->left;
                }else
                {
                    tree_root->right = NULL;
                }
                tree->id = 0;
                free(tree);
                return 1;
            }
        }else
        {
            if (*root == tree)
            {
                if (NULL != tree->right)
                {
                *root = tree->right;
                if (NULL != tree->left)
                {
                    transplantTree(tree->right, tree->left);
                }
                }else if(NULL != tree->left)
                {
                    *root = tree->left;
                }
                tree->id = 0;
                free(tree);
                return 1;
            }
        }
    }
    return 0;
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
