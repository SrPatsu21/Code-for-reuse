#ifndef BP_TREE
#define BP_TREE
// link https://www.programiz.com/dsa/b-plus-tree

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* Default order
#define ORDER 3

// Node
typedef struct SNode {
    void **pointers;
    int *keys;
    struct SNode *parent;
    bool is_leaf;
    int num_keys;
    struct SNode *next;
} NODE;

// Enqueue
void enqueue(NODE *new_node);

typedef struct record
{
    int value;
} record;

// Dequeue
NODE *dequeue(void);
int height(NODE *const root);
int pathToLeaves(NODE *const root, NODE *child);
void printLeaves(NODE *const root);
void printTree(NODE *const root);
void findAndPrint(NODE *const root, int key, bool verbose);
void findAndPrintRange(NODE *const root, int range1, int range2, bool verbose);
int findRange(NODE *const root, int key_start, int key_end, bool verbose, int returned_keys[], void *returned_pointers[]);
NODE *findLeaf(NODE *const root, int key, bool verbose);
record *find(NODE *root, int key, bool verbose, NODE **leaf_out);
int cut(int length);

record *makeRecord(int value);
NODE *makeNode(void);
NODE *makeLeaf(void);
int getLeftIndex(NODE *parent, NODE *left);
NODE *insertIntoLeaf(NODE *leaf, int key, record *pointer);
NODE *insertIntoLeafAfterSplitting(NODE *root, NODE *leaf, int key, record *pointer);
NODE *insertIntoNode(NODE *root, NODE *parent, int left_index, int key, NODE *right);
NODE *insertIntoNodeAfterSplitting(NODE *root, NODE *parent, int left_index, int key, NODE *right);
NODE *insertIntoParent(NODE *root, NODE *left, int key, NODE *right);
NODE *insertIntoNewRoot(NODE *left, int key, NODE *right);
NODE *startNewTree(int key, record *pointer);
NODE *insert(NODE *root, int key, int value);

#endif