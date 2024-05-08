#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct Tree
{
    struct Tree* right;
    struct Tree* left;
    struct Tree* root;
    char red;
    int id;
}TREE;

TREE* createNewTree(int id);
void freeTree(TREE* root);
TREE* findRoot(TREE* tree);
int insertOnRightSizeTree(TREE** adrs, TREE* root, int id);
int insertOnLeftSizeTree(TREE** adrs, TREE* root, int id);
int insertOnRBTree(TREE** adrs, TREE* root, int id);
int reInplantTree(TREE* root, TREE* tree);
int transplantTree(TREE* root, TREE* tree);
TREE* searchOnTree(TREE* root, int id);
TREE* searchLinearOnTree(TREE* root, int id);
int removeOnRBTree(TREE** root, TREE* tree, TREE* tree_root);
int removeOnRBTreeByid(TREE** root, int id);
int printInOrderTree(TREE* root);
int printPreOrderTree(TREE* root);
int printPostOrderTree(TREE* root);
TREE* maxTree(TREE* tree);
TREE* minTree(TREE* tree);
int rightRotate(TREE** adrs, TREE* tree);
int leftRotate(TREE** adrs, TREE* tree);


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
                    insertOnRBTree(&tree, tree, id);

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
                removeOnRBTreeByid(&tree, id);
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
            insertOnRBTree(&tree, tree, id);
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
        tree->red = 1;
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

int insertOnRightSizeTree(TREE** adrs, TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
    if (newtree != NULL)
    {
        root->right = newtree;
        root->right->root = root;
        RBFixUp(adrs, newtree);
        return 1;
    }else
    {
        return 0;
    }
};

int insertOnLeftSizeTree(TREE** adrs,TREE* root, int id)
{
    TREE* newtree = createNewTree(id);
    if (newtree != NULL)
    {
        root->left = newtree;
        root->left->root = root;
        RBFixUp(adrs, newtree);
        return 1;
    }else
    {
        // err
        return 0;
    }
};

int RBFixUp(TREE** adrs, TREE* tree)
{
    if (NULL != tree)
    {
        if (NULL != tree->root)
        {
            //while root = red
            while (1 == tree->root->red)
            {
                //if tree root is on left
                if (tree->root == tree->root->root->left)
                {
                    //the other side of the tree
                    TREE* aux = tree->root->root->right;
                    //if the other side is not null and red
                    if (NULL != aux && 1 == aux->red)
                    {
                        //???
                        tree->root->red = 0;
                        aux->red = 0;
                        tree->root->root->red = 1;
                        tree = tree->root->root;
                    //if the other side are NULL or black (is the same )
                    }else
                    {
                        //if tree igual to left side of its root
                        if (tree == tree->root->right) 
                        {
                            tree = tree->root;
                            leftRotate(adrs, tree);
                        }
                        tree->root->red = 0;
                        tree->root->root->red = 1;
                        rightRotate(adrs, tree->root->root);
                    }
                //tree root is on right
                }else   
                {
                    TREE* aux = tree->root->root->left;
                    //if the other side is not null and red
                    if (NULL != aux && 1 == aux->red) 
                    {
                        //???
                        tree->root->red = 0;
                        aux->red = 0;
                        tree->root->root->red = 1;
                        tree = tree->root->root;
                    //if the other side are NULL or black (is the same )
                    } else 
                    {
                        //if tree igual to left side of its root
                        if (tree == tree->root->left) 
                        {
                            tree = tree->root;
                            rightRotate(adrs, tree);
                        }
                        tree->root->red = 0;
                        tree->root->root->red = 1;
                        leftRotate(adrs, tree->root->root);
                    }
                }
            }
        }
    }
}

int insertOnRBTree(TREE** adrs, TREE* root, int id)
{
    if (root != NULL)
    {   
        if (id > root->id)
        {
            if (NULL != root->right)
            {
                insertOnRBTree(adrs, root->right, id);
            }else
            {
                insertOnRightSizeTree(adrs, root, id);
            }
        }else if(id < root->id)
        {
            if (NULL != root->left)
            {
                insertOnRBTree(adrs, root->left, id);
            }else
            {
                insertOnLeftSizeTree(adrs, root, id);
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

int removeOnRBTreeByid(TREE** root, int id)
{
    TREE* t = searchOnTree(*root, id);
    TREE* tree_root = findParent(*root, t);
    return removeOnRBTree(root, t, tree_root);
};

int removeOnRBTree(TREE** root, TREE* tree, TREE* tree_root)
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

int rightRotate(TREE** adrs, TREE* tree)
{
    //aux = left
    TREE* aux = tree->left;
    //tree left = aux right
    tree->left = aux->right;
    if (aux->right != NULL)
    {
        aux->right->root = tree;
    }
    aux->root = tree->root;
    //if root = null : first
    if (tree->root == NULL) 
    {
        *adrs = aux;
    // if root right = tree
    } else if (tree == tree->root->right) 
    {
        tree->root->right = aux;
    //if root left = tree
    } else 
    {
        tree->root->left = aux;
    }
    aux->right = tree;
    tree->root = aux;    
};

int leftRotate(TREE** adrs, TREE* tree)
{
    TREE* aux = tree->right;
    tree->right = aux->left;
    if (aux->left != NULL) {
        aux->left->root = tree;
    }
    aux->root = tree->root;
    if (tree->root == NULL) {
        *adrs = aux;
    } else if (tree == tree->root->left) {
        tree->root->left = aux;
    } else {
        tree->root->right = aux;
    }
    aux->left = tree;
    tree->root = aux;
};