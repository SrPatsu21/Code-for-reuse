#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include for bool type

struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    bool color; // true = RED; false = BLACK
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->color = false; // Assigning black!

    return node;
}

void LEFT_ROTATE(struct node** root, struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RIGHT_ROTATE(struct node** root, struct node* x) {
    struct node* y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RB_INSERT_FIXUP(struct node** root, struct node* z) {
    while (z->parent->color == true) {
        if (z->parent == z->parent->parent->left) {
            struct node* y = z->parent->parent->right;
            if (y != NULL && y->color == true) {
                z->parent->color = false;
                y->color = false;
                z->parent->parent->color = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    LEFT_ROTATE(root, z);
                }
                z->parent->color = false;
                z->parent->parent->color = true;
                RIGHT_ROTATE(root, z->parent->parent);
            }
        } else {
            struct node* y = z->parent->parent->left;
            if (y != NULL && y->color == true) {
                z->parent->color = false;
                y->color = false;
                z->parent->parent->color = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RIGHT_ROTATE(root, z);
                }
                z->parent->color = false;
                z->parent->parent->color = true;
                LEFT_ROTATE(root, z->parent->parent);
            }
        }
    }
    (*root)->color = false;
}

void RB_INSERT(struct node** root, struct node* z) {
    struct node* y = NULL;
    struct node* x = *root;
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = NULL;
    z->right = NULL;
    z->color = true; // Assigning red
    RB_INSERT_FIXUP(root, z);
}

// Function to print a Red-Black tree
void printRBTree(struct node* root, int level) {
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    level += 10;

    // Process right child first
    printRBTree(root->right, level);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < level; i++) {
        printf(" ");
    }
    if (root->color == true) {
        printf("%d(R)", root->data);
    } else {
        printf("%d(B)", root->data);
    }

    // Process left child
    printRBTree(root->left, level);
}

void RB_TRANSPLANT(struct node** root, struct node* u, struct node* v) {
    if (u->parent == NULL) {
        *root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

void RB_DELETE_FIXUP(struct node** root, struct node* x) {
    while (x != *root && x->color == false) {
        if (x == x->parent->left) {
            struct node* w = x->parent->right;
            if (w->color == true) {
                w->color = false;
                x->parent->color = true;
                LEFT_ROTATE(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == false && w->right->color == false) {
                w->color = true;
                x = x->parent;
            } else {
                if (w->right->color == false) {
                    w->left->color = false;
                    w->color = true;
                    RIGHT_ROTATE(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->right->color = false;
                LEFT_ROTATE(root, x->parent);
                x = *root;
            }
        } else {
            struct node* w = x->parent->left;
            if (w->color == true) {
                w->color = false;
                x->parent->color = true;
                RIGHT_ROTATE(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == false && w->left->color == false) {
                w->color = true;
                x = x->parent;
            } else {
                if (w->left->color == false) {
                    w->right->color = false;
                    w->color = true;
                    LEFT_ROTATE(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->left->color = false;
                RIGHT_ROTATE(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = false;
}

struct node* RB_TREE_MINIMUM(struct node* root, struct node* x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

void RB_DELETE(struct node** root, struct node* z) {
    struct node* y = z;
    struct node* x;
    bool y_original_color = y->color;
    if (z->left == NULL) {
        x = z->right;
        RB_TRANSPLANT(root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        RB_TRANSPLANT(root, z, z->left);
    } else {
        y = RB_TREE_MINIMUM(*root, z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            RB_TRANSPLANT(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RB_TRANSPLANT(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_original_color == false) {
        RB_DELETE_FIXUP(root, x);
    }
}

// Driver code
int main() {
    // TREE
    //26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3

    // ROOT
    struct node* root = newNode(26); // default is black
    root->parent = NULL;
    
    // LINE 1
    root->left = newNode(17);
    root->left->color = true; // Assigning red
    root->left->parent = root;
    root->right = newNode(41);
    root->right->parent = root;

    // LINE 2
    root->left->left = newNode(14);
    root->left->left->parent = root->left;
    root->left->right = newNode(21);
    root->left->right->parent = root->left;
    root->right->left = newNode(30);
    root->right->left->color = true; // Assigning red
    root->right->left->parent = root->right;
    root->right->right = newNode(47);
    root->right->right->parent = root->right;

    // LINE 3
    root->left->left->left = newNode(10);
    root->left->left->left->color = true; // Assigning red
    root->left->left->left->parent = root->left->left;
    root->left->left->right = newNode(16);
    root->left->left->right->parent = root->left->left;
    root->left->right->left = newNode(19);
    root->left->right->left->parent = root->left->right;
    root->left->right->right = newNode(23);
    root->left->right->right->parent = root->left->right;
    root->right->left->left = newNode(28);
    root->right->left->left->parent = root->right->left;
    root->right->left->right = newNode(38);
    root->right->left->right->parent = root->right->left;

    // LINE 4
    root->left->left->left->left = newNode(7);
    root->left->left->left->left->parent = root->left->left->left;
    root->left->left->left->right = newNode(12);
    root->left->left->left->right->parent = root->left->left->left;
    root->left->left->right->left = newNode(15);
    root->left->left->right->left->color = true; // Assigning red
    root->left->left->right->left->parent = root->left->left->right;
    root->left->right->left->right = newNode(20);
    root->left->right->left->right->color = true; // Assigning red
    root->left->right->left->right->parent = root->left->right->left;
    root->right->left->right->left = newNode(35);
    root->right->left->right->left->color = true; // Assigning red
    root->right->left->right->left->parent = root->right->left->right;
    root->right->left->right->right = newNode(39);
    root->right->left->right->right->color = true; // Assigning red
    root->right->left->right->right->parent = root->right->left->right;

    // LINE 5
    root->left->left->left->left->left = newNode(3);
    root->left->left->left->left->left->color = true; // Assigning red
    root->left->left->left->left->left->parent = root->left->left->left->left;

    // Print the Red-Black tree
    printRBTree(root, 0);

    printf("\n\n");
    printf("----------------------------------------\n");
    struct node* node_18 = newNode(18);
    RB_INSERT(&root, node_18);
    printRBTree(root, 0);

    printf("\n\n");
    printf("----------------------------------------\n");
    struct node* node_1 = newNode(1);
    RB_INSERT(&root, node_1);
    printRBTree(root, 0);

    printf("\n\n");
    printf("----------------------------------------\n");
    // delete node 14
    RB_DELETE(&root, root->left->left);
    printRBTree(root, 0);

    printf("\n\n");
    return 0;
}