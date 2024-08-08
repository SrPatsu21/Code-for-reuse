#include "B+tree.h"

int main() {
  NODE *root;
  char instruction;

  root = NULL;

  root = insert(root, 5, 33);
  root = insert(root, 15, 21);
  root = insert(root, 25, 31);
  root = insert(root, 35, 41);
  root = insert(root, 45, 10);

  printTree(root);

  findAndPrint(root, 15, instruction = 'a');
}