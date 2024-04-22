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
TREE* findRoot(TREE* tree);
int insertOnRigthSizeTree(TREE* root, int info);
int insertOnLeftSizeTree(TREE* root, int info);
int insertOnTree(TREE* root, int info);
int transplantTree(TREE* root, TREE* tree);
int reImplantTree(TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int info);
TREE* searchLinearOnTree(TREE* root, int info);
int removeOnTree(TREE** root, int info);
int transpouseOnTree(TREE* tree);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);
int getBalanceTreeAVL(TREE* tree);
int manageSwap(TREE** adrs, TREE* tree);
int makeRRAVL(TREE** adrs, TREE* tree);
int makeLLAVL(TREE** adrs, TREE* tree);
int makeRLAVL(TREE** adrs, TREE* tree);
int makeLRAVL(TREE** adrs, TREE* tree);
int insertOnTreeAVL(TREE** adrs, TREE* root, int info);
int removeOnTreeAVL(TREE** adrs, TREE* tree);


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
                insertOnTreeAVL(&tree, tree, info);

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
            insertOnTreeAVL(&tree, tree, info);
        }
    }
    tree = findRoot(tree);
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
    if (root != NULL)
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
    }else
    {
        printf("null root\n");
        return 0;
    }
    return 1;
};

int transplantTree(TREE* root, TREE* tree)
{
    if (tree != NULL && root != NULL)
    {
        if (tree->info > root->info)
        {
            if (NULL != root->right)
            {
                transplantTree(root->right, tree);
            }else
            {
                root->right = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return transplantTree(findRoot(root), r) * transplantTree(findRoot(root), l);
            }
        }else if(tree->info < root->info)
        {
            if (NULL != root->left)
            {
                transplantTree(root->left, tree);
            }else
            {
                root->left = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return transplantTree(findRoot(root), r) * transplantTree(findRoot(root), l);
            }
        }else if (tree->info == root->info)
        {
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;
                return transplantTree(findRoot(root), r) * transplantTree(findRoot(root), l);
        }
    }else if (NULL == root)
    {
        return 0;
    }
    return 1;
};

int reInplantTree(TREE* root, TREE* tree)
{
    if (tree->info > root->info)
    {
        if (NULL != root->right)
        {
            reInplantTree(root->right, tree);
        }else
        {
            root->right = tree;
        }
    }else if(tree->info < root->info)
    {
        if (NULL != root->left)
        {
            reInplantTree(root->left, tree);
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
                        reImplantTree(t->right, t->left);
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
                        reImplantTree(t->right, t->left);
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
                        reImplantTree(t->right, t->left);
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

int getBalanceTreeAVL(TREE* tree)
{
    if (NULL != tree)
    {
        int r = getBalanceTreeAVL(tree->right);
        int l = getBalanceTreeAVL(tree->left);     
        if (r > l)
        {
            return 1 + r;
        }else
        {
            return 1 + l;
        }           
    }else
    {
        return 0;
    }
};

//wont work
int manageSwap(TREE** adrs, TREE* tree)
{
    int r = getBalanceTreeAVL(tree->right);
    int l = getBalanceTreeAVL(tree->left);     
    if (r > l)
    {
        r = getBalanceTreeAVL(tree->right->right);
        l = getBalanceTreeAVL(tree->right->left);     
        if (r > (l+1))
        {
            makeRRAVL(adrs, tree);
        }else if(l > (r+1))
        {
            makeRLAVLadrs(adrs, tree);
        }
    }else if (r < l)
    {
        r = getBalanceTreeAVL(tree->left->right);
        l = getBalanceTreeAVL(tree->left->left);     
        if (r > (l+1))
        {
            makeLRAVL(adrs, tree);
        }else if(l > (r+1))
        {
            makeLLAVL(adrs, tree);
        }
    }
    return 0;
};

int makeRRAVL(TREE** adrs, TREE* tree)
{
    tree->right->root = tree->root;

    if (NULL != tree->root)
    {
        if (tree == tree->root->left)
        {
            tree->root->left = tree->right;
        }else if (tree == tree->root->right)
        {
            tree->root->right = tree->right;
        }
    }    

    tree->root = tree->right;
    tree->right = NULL;
    reImplantTree(tree->root, tree);

    if (NULL == tree->root->root)
    {
        adrs = tree->root;
    }
};

int makeLLAVL(TREE** adrs, TREE* tree)
{
    tree->left->root = tree->root;

    if (NULL != tree->root)
    {
        if (tree == tree->root->left)
        {
            tree->root->left = tree->left;
        }else if (tree == tree->root->right)
        {
            tree->root->right = tree->left;
        }
    }    

    tree->root = tree->left;
    tree->left = NULL;
    reImplantTree(tree->root, tree);

    if (NULL == tree->root->root)
    {
        adrs = tree->root;
    }
};

int makeRLAVL(TREE** adrs, TREE* tree)
{
    tree->right->left->root = tree->root;

    if (NULL != tree->root)
    {
        if (tree == tree->root->left)
        {
            tree->root->left = tree->right->left;
        }else if (tree == tree->root->right)
        {
            tree->root->right = tree->right->left;
        }
    }    

    tree->root = tree->right->left;
    tree->right->left = NULL;
    reImplantTree(tree->root, tree->right);
    tree->right = NULL;
    reImplantTree(tree->root, tree);

    if (NULL == tree->root->root)
    {
        adrs = tree->root;
    }
};

int makeLRAVL(TREE** adrs, TREE* tree)
{
    tree->left->right->root = tree->root;

    if (NULL != tree->root)
    {
        if (tree == tree->root->left)
        {
            tree->root->left = tree->left->right;
        }else if (tree == tree->root->right)
        {
            tree->root->right = tree->left->right;
        }
    }    

    tree->root = tree->left->right;
    tree->left->right = NULL;
    reImplantTree(tree->root, tree->left);
    tree->left = NULL;
    reImplantTree(tree->root, tree);

    if (NULL == tree->root->root)
    {
        adrs = tree->root;
    }
};

//when call the first TREE problem

int insertOnTreeAVL(TREE** adrs, TREE* root, int info)
{
    if (root != NULL)
    {   
        if (info > root->info)
        {
            if (NULL != root->right)
            {
                insertOnTreeAVL(adrs, root->right, info);
            }else
            {
                insertOnRigthSizeTree(root, info);
            }
        }else if(info < root->info)
        {
            if (NULL != root->left)
            {
                insertOnTreeAVL(adrs ,root->left, info);
            }else
            {
                insertOnLeftSizeTree(root, info);
            }
        }else
        {
            return 0;
        }
        manageSwap(adrs, root->root);
    }else
    {
        adrs = createNewTree(info);
    }
    	    
    return 1;
};

int removeOnTreeAVL(TREE** adrs, TREE* tree)
{

};