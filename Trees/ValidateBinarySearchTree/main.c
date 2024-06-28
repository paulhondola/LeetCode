/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

bool isValidBST_aux(tree root, long long int low, long long int high) {
  if (root == NULL)
    return true;

  if (root->val <= low || root->val >= high)
    return false;

  return isValidBST_aux(root->left, low, root->val) &&
         isValidBST_aux(root->right, root->val, high);
}

bool isValidBST(tree root) {
  return isValidBST_aux(root, LONG_LONG_MIN, LONG_LONG_MAX);
}
