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
TREE* findParent(TREE* root, TREE* tree);
int insertOnRightSizeTree(TREE* root, int id);
int insertOnLeftSizeTree(TREE* root, int id);
int insertOnTree(TREE* root, int id);
int transplantTree(TREE* root, TREE* tree);
int reInplantTree(TREE* main_root, TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int id);
TREE* searchLinearOnTree(TREE* root, int id);
int removeOnTree(TREE** root, TREE* tree, TREE* t_root);
int removeOnTreeByid(TREE** root, int id);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);
//AVL
int getTreeSize(TREE* tree);
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
                insertOnTree(tree, id);

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
            tree = createNewTree(id);
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

TREE* findParent(TREE* root, TREE* tree)
{
    if (root->left == tree || root->right == tree)
    {
        return root;
    }else
    {
        if (root->id > tree->id)
        {
            return findParent(root->left, tree);
        }else if (root->id < tree->id)
        {
            return findParent(root->right, tree);
        }else
        {
            return NULL;
        }
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
        // err
        return 0;
    }
};

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

int reInplantTree(TREE* main_root, TREE* root, TREE* tree)
{
    if (tree != NULL && root != NULL)
    {
        if (tree->id > root->id)
        {
            if (NULL != root->right)
            {
                reInplantTree(main_root ,root->right, tree);
            }else
            {
                root->right = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return reInplantTree(main_root, main_root, r) * reInplantTree(main_root, main_root, l);
            }
        }else if(tree->id < root->id)
        {
            if (NULL != root->left)
            {
                reInplantTree(main_root, root->left, tree);
            }else
            {
                root->left = tree;
                TREE* r = tree->right;
                TREE* l = tree->left;
                tree->right = NULL;
                tree->left = NULL;

                return reInplantTree(main_root, main_root, r) * reInplantTree(main_root, main_root, l);
            }
        }else if (tree->id == root->id)
        {
            return 0;
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
    TREE* t_root = findParent(*root, t);
    return removeOnTree(root, t, t_root);
};
int removeOnTree(TREE** root, TREE* tree, TREE* t_root)
{
    if (NULL != tree)
    {
        if (NULL != t_root)
        {
            if (t_root->left == tree)
            {
                if (NULL != tree->right)
                {
                    t_root->left = tree->right;
                    if (NULL != tree->left)
                    {
                        transplantTree(tree->right, tree->left);
                    }
                }else if(NULL != tree->left)
                {
                    t_root->left = tree->left;
                }else
                {
                    t_root->left = NULL;
                }
                tree->id = 0;
                free(tree);
                return 1;
            }else if (t_root->right == tree)
            {
                if (NULL != tree->right)
                {
                    t_root->right = tree->right;
                    if (NULL != tree->left)
                    {
                        transplantTree(tree->right, tree->left);
                    }
                }else if(NULL != tree->left)
                {
                    t_root->right = tree->left;
                }else
                {
                    t_root->right = NULL;
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
    printf("not found");
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

//errado
int getTreeSize(TREE* tree)
{
    if (NULL != tree)
    {
        int r = getTreeSize(tree->right);
        int l = getTreeSize(tree->left);     
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
    int r = getTreeSize(tree->right);
    int l = getTreeSize(tree->left);     
    if (r > (l+1))
    {
        r = getTreeSize(tree->right->right);
        l = getTreeSize(tree->right->left);     
        if (r < l)
        {
            return makeRLAVLadrs(adrs, tree);
        }else
        {
            return makeRRAVL(adrs, tree);
        }
    }else if (l < (r+1))
    {
        r = getTreeSize(tree->left->right);
        l = getTreeSize(tree->left->left);     
        if (r > l)
        {
            return makeLRAVL(adrs, tree);
        }else
        {
            return makeLLAVL(adrs, tree);
        }
    }
    return 0;
};

int makeRRAVL(TREE** adrs, TREE* tree)
{
    TREE* root = findParent(*adrs, tree);
    TREE* treer = tree->right;
    if (NULL != root)
    {
        if (tree == root->left)
        {
            root->left = treer;
        }else if (tree == root->right)
        {
            root->right = treer;
        }
    }    

    TREE* aux = treer->left;
    treer->left = NULL;
    tree->right = NULL;
    treer->left = tree;
    transplantTree(root, aux);

    if (NULL == root)
    {
        adrs = treer;
    }
};

int makeLLAVL(TREE** adrs, TREE* tree)
{
    // tree->left->root = tree->root;

    // if (NULL != tree->root)
    // {
    //     if (tree == tree->root->left)
    //     {
    //         tree->root->left = tree->left;
    //     }else if (tree == tree->root->right)
    //     {
    //         tree->root->right = tree->left;
    //     }
    // }    

    // tree->root = tree->left;
    // tree->left = NULL;
    // reImplantTree(tree->root, tree);

    // if (NULL == tree->root->root)
    // {
    //     adrs = tree->root;
    // }
};

int makeRLAVL(TREE** adrs, TREE* tree)
{
    // tree->right->left->root = tree->root;

    // if (NULL != tree->root)
    // {
    //     if (tree == tree->root->left)
    //     {
    //         tree->root->left = tree->right->left;
    //     }else if (tree == tree->root->right)
    //     {
    //         tree->root->right = tree->right->left;
    //     }
    // }    

    // tree->root = tree->right->left;
    // tree->right->left = NULL;
    // reImplantTree(tree->root, tree->right);
    // tree->right = NULL;
    // reImplantTree(tree->root, tree);

    // if (NULL == tree->root->root)
    // {
    //     adrs = tree->root;
    // }
};

int makeLRAVL(TREE** adrs, TREE* tree)
{
    // tree->left->right->root = tree->root;
    // 
    // if (NULL != tree->root)
    // {
    //     if (tree == tree->root->left)
    //     {
    //         tree->root->left = tree->left->right;
    //     }else if (tree == tree->root->right)
    //     {
    //         tree->root->right = tree->left->right;
    //     }
    // }    

    // tree->root = tree->left->right;
    // tree->left->right = NULL;
    // reImplantTree(tree->root, tree->left);
    // tree->left = NULL;
    // reImplantTree(tree->root, tree);

    // if (NULL == tree->root->root)
    // {
    //     adrs = tree->root;
    // }
};

int insertOnTreeAVL(TREE** adrs, TREE* root, int info)
{
    // if (root != NULL)
    // {   
    //     if (info > root->info)
    //     {
    //         if (NULL != root->right)
    //         {
    //             insertOnTreeAVL(adrs, root->right, info);
    //         }else
    //         {
    //             insertOnRightSizeTree(root, info);
    //         }
    //     }else if(info < root->info)
    //     {
    //         if (NULL != root->left)
    //         {
    //             insertOnTreeAVL(adrs ,root->left, info);
    //         }else
    //         {
    //             insertOnLeftSizeTree(root, info);
    //         }
    //     }else
    //     {
    //         return 0;
    //     }
    //     manageSwap(adrs, root->root);
    // }else
    // {
    //     adrs = createNewTree(info);
    // }
    	    
    // return 1;
};

int removeOnTreeAVL(TREE** adrs, TREE* tree)
{

};