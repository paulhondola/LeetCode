/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

void inorder(tree root, int *prev, int *min) {
  if (root == NULL) {
    return;
  }

  inorder(root->left, prev, min);

  if (*prev != -1) {
    int diff = root->val - *prev;
    if (diff < *min) {
      *min = diff;
    }
  }

  *prev = root->val;

  inorder(root->right, prev, min);
}

int getMinimumDifference(tree root) {
  int min = INT_MAX;
  int prev = -1;
  inorder(root, &prev, &min);
  return min;
}
