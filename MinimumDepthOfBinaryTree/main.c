#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

int minDepth(tree root) {

  if (root == NULL)
    return 0;

  int left = minDepth(root->left);
  int right = minDepth(root->right);

  if (left == 0)
    return right + 1;
  else if (right == 0)
    return left + 1;
  else
    return left < right ? left + 1 : right + 1;
}
