#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

bool isSameTree(tree p, tree q) {
  if (p == NULL && q == NULL) {
    return true;
  }

  if (p == NULL || q == NULL) {
    return false;
  }

  if (p->val != q->val) {
    return false;
  }

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
