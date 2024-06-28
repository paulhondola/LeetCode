/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

int countNodes(tree root) {
  if (root == NULL)
    return 0;

  return 1 + countNodes(root->left) + countNodes(root->right);
}
