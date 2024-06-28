#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

const int MAX_NODES = 1000;
int nodes[MAX_NODES];
int nodesCount = 0;
void get_tree(tree root) {

  if (root == NULL)
    return;

  get_tree(root->left);
  nodes[nodesCount++] = root->val;
  get_tree(root->right);
}

int kthSmallest(tree root, int k) { return nodes[k - 1]; }
