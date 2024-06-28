#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int diameterOfBinaryTree_aux(struct TreeNode *root, int *diameter) {
  if (root == NULL)
    return 0;

  int left = diameterOfBinaryTree_aux(root->left, diameter);
  int right = diameterOfBinaryTree_aux(root->right, diameter);

  *diameter = (*diameter > (left + right)) ? *diameter : (left + right);

  return 1 + ((left > right) ? left : right);
}

int diameterOfBinaryTree(struct TreeNode *root) {
  int diameter = 0;
  diameterOfBinaryTree_aux(root, &diameter);
  return diameter;
}
