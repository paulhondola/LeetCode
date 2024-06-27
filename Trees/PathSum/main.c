#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

bool hasPathSum(tree root, int targetSum) {
    // reach the end of the tree
    if(root == NULL)
        return false;

    // reach the leaf node
    if(root->left == NULL && root->right == NULL)
        return targetSum == root->val;

    // check left and right while subtracting the current value from the target sum
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
