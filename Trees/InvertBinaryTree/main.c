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

tree invertTree(tree root) {
  if (root == NULL)
    return NULL;

  tree left = invertTree(root->left);
  tree right = invertTree(root->right);

  root->left = right;
  root->right = left;

  return root;
}
