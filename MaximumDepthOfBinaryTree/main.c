#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

int maxDepth(tree root) {
  if (root == NULL)
    return 0;

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  return left > right ? left + 1 : right + 1;
}
