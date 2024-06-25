#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

tree new_node(int val) {
  tree n = (tree)malloc(sizeof(struct TreeNode));
  if (n == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

tree aux(int *nums, int start, int end)
{
    if(start > end)
        return NULL;

    int mid = (start + end) / 2;

    tree root = new_node(nums[mid]);

    // check left
    root->left = aux(nums, start, mid - 1);
    // check right
    root->right = aux(nums, mid + 1, end);

    return root;
}

tree sortedArrayToBST(int* nums, int numsSize) {
    return aux(nums, 0, numsSize - 1);
}
