#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void inorder(struct TreeNode *root, bool nodes[]) {
  if (root == NULL) {
    return;
  }
  inorder(root->left, nodes); // Corrected
  nodes[root->val] = true;
  inorder(root->right, nodes); // Corrected
}

struct TreeNode *increasingBST(struct TreeNode *root) {
  bool nodes[1001] = {false};
  inorder(root, nodes);

  int index = 0;
  while (!nodes[index]) {
    index++;
  }

  struct TreeNode *newRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  struct TreeNode *current = newRoot;
  current->val = index;
  current->left = NULL;  // Ensure left is NULL
  current->right = NULL; // Ensure right is initialized

  index++;

  while (index < 1001) { // Use 1001 for safer upper bound
    if (nodes[index]) {
      current->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      current = current->right;
      current->val = index;
      current->left = NULL;  // Properly initialize left pointer
      current->right = NULL; // Initialize right pointer for next iteration
    }
    index++;
  }

  return newRoot;
}
