#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Helper function for the in-order traversal to find the kth smallest element.
void inOrderTraversal(struct TreeNode *root, int *k, int *result) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left, k, result);

  (*k)--;
  if (*k == 0) {
    *result = root->val;
    return;
  }

  inOrderTraversal(root->right, k, result);
}

// Function to find the kth smallest element in a BST.
int kthSmallest(struct TreeNode *root, int k) {
  int result = -1;
  inOrderTraversal(root, &k, &result);
  return result;
}
