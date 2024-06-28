#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

const int max_nodes = 100;

typedef struct TreeNode *tree;

void postorderTraversal_aux(tree root, int *returnSize, int *nodes) {
  if (root == NULL)
    return;

  // SDR
  postorderTraversal_aux(root->left, returnSize, nodes);
  postorderTraversal_aux(root->right, returnSize, nodes);
  nodes[(*returnSize)++] = root->val;
}

int *postorderTraversal(tree root, int *returnSize) {

  int index = 0;
  int *nodes = (int *)malloc(max_nodes * sizeof(int));
  *returnSize = 0;

  postorderTraversal_aux(root, returnSize, nodes);

  return nodes;
}
