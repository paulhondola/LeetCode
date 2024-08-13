#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode *newNode(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Helper function to find the depth and parent of a node
void findDepthAndParent(struct TreeNode *root, int node, int depth, int parent,
                        int *foundDepth, int *foundParent) {
  if (root == NULL)
    return;

  if ((root->left != NULL && root->left->val == node) ||
      (root->right != NULL && root->right->val == node)) {
    *foundDepth = depth + 1;
    *foundParent = root->val;
    return;
  }

  findDepthAndParent(root->left, node, depth + 1, root->val, foundDepth,
                     foundParent);
  findDepthAndParent(root->right, node, depth + 1, root->val, foundDepth,
                     foundParent);
}

bool isCousins(struct TreeNode *root, int x, int y) {
  if (root == NULL)
    return 0;

  int xDepth = -1, yDepth = -1;
  int xParent = -1, yParent = -1;

  findDepthAndParent(root, x, 0, root->val, &xDepth, &xParent);
  findDepthAndParent(root, y, 0, root->val, &yDepth, &yParent);

  // Check if they are at the same level but have different parents
  return (xDepth == yDepth) && (xParent != yParent);
}

// Example usage
int main() {
  // Construct the binary tree
  //        1
  //       / \
    //      2   3
  //     /     \
    //    4       5
  struct TreeNode *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->right->right = newNode(5);

  // Check if 4 and 5 are cousins
  if (isCousins(root, 4, 5)) {
    printf("4 and 5 are cousins.\n");
  } else {
    printf("4 and 5 are not cousins.\n");
  }

  return 0;
}
