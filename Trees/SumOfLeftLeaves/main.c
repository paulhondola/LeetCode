#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

int sumOfLeftLeaves(struct TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root->left != NULL && root->left->left == NULL &&
      root->left->right == NULL)
    return root->left->val + sumOfLeftLeaves(root->right);
  else
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
