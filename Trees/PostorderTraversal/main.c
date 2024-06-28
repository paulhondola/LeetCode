#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

const int max_nodes = 100;

typedef struct TreeNode *tree;

void preorderTraversal_aux(tree root, int *returnSize, int *nodes) {
  if (root == NULL)
    return;

  // RSD

  nodes[(*returnSize)++;] = root->val;

  preorderTraversal_aux(root->left, returnSize, nodes);
  preorderTraversal_aux(root->right, returnSize, nodes);
}

int *preorderTraversal(tree root, int *returnSize) {

  int index = 0;
  int *nodes = (int *)malloc(max_nodes * sizeof(int));
  *returnSize = 0;

  preorderTraversal_aux(root, returnSize, nodes);

  return nodes;
}
