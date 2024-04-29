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
int insertOnTree(TREE** adrs, TREE* root, int info);
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
int verifyDirectionalAVLTree(TREE** adrs, TREE* tree, int id);
int verifyAllAVLTree(TREE** adrs, TREE* tree);
int makeRRAVL(TREE** adrs, TREE* tree);
int makeLLAVL(TREE** adrs, TREE* tree);
int makeRLAVL(TREE** adrs, TREE* tree);
int makeLRAVL(TREE** adrs, TREE* tree);
int insertOnTreeAVL(TREE** adrs, TREE* root, int info);
int removeOnTreeAVLById(TREE** root, TREE* tree, int id);
int removeOnTreeAVL(TREE** root, TREE* tree, TREE* t_root);



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
                insertOnTreeAVL(&tree, tree, id);

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
            insertOnTreeAVL(&tree, tree, id);
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

int insertOnTree(TREE** adrs, TREE* root, int info)
{
    if (root != NULL)
    {   
        if (info > root->id)
        {
            if (NULL != root->right)
            {
                insertOnTree(adrs, root->right, info);
            }else
            {
                insertOnRightSizeTree(root, info);
            }
        }else if(info < root->id)
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
        *adrs = createNewTree(info);
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
    if (NULL != root && NULL != tree)
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

int manageSwap(TREE** adrs, TREE* tree)
{    
    int r = getTreeSize(tree->right);
    int l = getTreeSize(tree->left);
    if (r > 1 || l > 1)
    {    
        if (r > (l+1))
        {
            r = getTreeSize(tree->right->right);
            l = getTreeSize(tree->right->left);   
  
            if (r < l)
            {
                printf("\nRL\n");
                return makeRLAVL(adrs, tree);
            }else
            {
                printf("\nRR\n");
                return makeRRAVL(adrs, tree);
            }
        }else if (l > (r+1))
        {
            r = getTreeSize(tree->left->right);
            l = getTreeSize(tree->left->left);   
  
            if (r > l)
            {
                printf("\nLR\n");
                return makeLRAVL(adrs, tree);
            }else
            {
                printf("\nLL\n");
                return makeLLAVL(adrs, tree);
            }
        }
    }
    return 0;
};

int verifyAllAVLTree(TREE** adrs, TREE* tree)
{
    if (NULL != tree)
    {
        manageSwap(adrs, tree);
        verifyAllAVLTree(adrs, tree->left);
        verifyAllAVLTree(adrs, tree->right);
    }
    return 0;
}

int verifyDirectionalAVLTree(TREE** adrs, TREE* tree, int id)
{
    if (NULL != tree)
    {
        manageSwap(adrs, tree);
        if (id < tree->id)
        {
            verifyDirectionalAVLTree(adrs, tree->left, id);
        }else if (id > tree->id)
        {
            verifyDirectionalAVLTree(adrs, tree->right, id);
        }
    }
    return 0;
};

int makeRRAVL(TREE** adrs, TREE* tree)
{
    printf("t");
    //parent of those
    TREE* root = findParent(*adrs, tree);
    //node who will be the first
    TREE* treer = tree->right;
    //if there is a root
    if (NULL != root)
    {
        //set the new node on a side o the tree
        if (tree == root->left)
        {
            root->left = treer;
        }else if (tree == root->right)
        {
            root->right = treer;
        }
    }else
    {
        //if it was the root
        *adrs = treer;
    }
    
    //aux will be transplanted
    TREE* aux = treer->left;
    treer->left = NULL;
    //remove treer from the tree
    tree->right = NULL;
    //insert tree on treer
    treer->left = tree;
    //transplant aux
    transplantTree(treer, aux);
};

int makeLLAVL(TREE** adrs, TREE* tree)
{
    //parent of those
    TREE* root = findParent(*adrs, tree);
    //node who will be the first
    TREE* treer = tree->left;
    //if there is a root
    if (NULL != root)
    {
        //set the new node on a side o the tree
        if (tree == root->left)
        {
            root->left = treer;
        }else if (tree == root->right)
        {
            root->right = treer;
        }
    }else
    {
        //if it was the root
        *adrs = treer;
    }    
    //aux will be transplanted
    TREE* aux = treer->right;
    treer->right = NULL;
    //remove treer from the old tree
    tree->left = NULL;
    //insert tree on treer
    treer->right = tree;
    //transplant aux
    transplantTree(treer, aux);
};

int makeRLAVL(TREE** adrs, TREE* tree)
{
    //parent of those
    TREE* root = findParent(*adrs, tree);
    //node who will be the first
    TREE* treer = tree->right->left;
    //if there is a root
    if (NULL != root)
    {
        //set the new node on a side o the tree
        if (tree == root->left)
        {
            root->left = treer;
        }else if (tree == root->right)
        {
            root->right = treer;
        }
    }else
    {
        //if it was the root
        *adrs = treer;
    } 
    //aux will be transplanted
    TREE* aux1 = treer->left;
    treer->left = NULL;
    TREE* aux2 = treer->right;
    treer->right = NULL;
    //remove treer from the old tree
    tree->right->left = NULL;
    //insert tree on treer
    treer->right = tree;
    treer->left = tree->left;
    tree->left = NULL;
    //transplant aux
    transplantTree(treer, aux1);
    transplantTree(treer, aux2);  
};

int makeLRAVL(TREE** adrs, TREE* tree)
{
   //parent of those
    TREE* root = findParent(*adrs, tree);
    //node who will be the first
    TREE* treer = tree->left->right;
    //if there is a root
    if (NULL != root)
    {
        //set the new node on a side o the tree
        if (tree == root->left)
        {
            root->left = treer;
        }else if (tree == root->right)
        {
            root->right = treer;
        }
    }else
    {
        //if it was the root
        *adrs = treer;
    }     
    //aux will be transplanted
    TREE* aux1 = treer->left;
    treer->left = NULL;
    TREE* aux2 = treer->right;
    treer->right = NULL;
    //remove treer from the old tree
    tree->left->right = NULL;
    //insert tree on treer
    treer->right = tree;
    treer->left = tree->right;
    tree->right = NULL;
    //transplant aux
    transplantTree(treer, aux1);
    transplantTree(treer, aux2);
};

int insertOnTreeAVL(TREE** adrs, TREE* root, int info)
{
    if (root != NULL)
    {   
        if (info > root->id)
        {
            if (NULL != root->right)
            {
                insertOnTreeAVL(adrs, root->right, info);
            }else
            {
                insertOnRightSizeTree(root, info);
                verifyDirectionalAVLTree(adrs, *adrs, info);
            }
        }else if(info < root->id)
        {
            if (NULL != root->left)
            {
                insertOnTreeAVL(adrs, root->left, info);
            }else
            {
                insertOnLeftSizeTree(root, info);
                verifyDirectionalAVLTree(adrs, *adrs, info);
            }
        }else
        {
            return 0;
        }
    }else
    {
        *adrs = createNewTree(info);
    }
    	    
    return 1;
};

int removeOnTreeAVL(TREE** root, TREE* tree, TREE* t_root)
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