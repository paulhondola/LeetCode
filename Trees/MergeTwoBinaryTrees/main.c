#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

tree merge(tree t1, tree t2) {
  if (!t1 && !t2)
    return NULL;
  if (!t1)
    return t2;
  if (!t2)
    return t1;

  // Merge the values of the current nodes
  t1->val += t2->val;

  // Recursively merge the left and right subtrees
  t1->left = merge(t1->left, t2->left);
  t1->right = merge(t1->right, t2->right);

  return t1;
}

tree mergeTrees(tree root1, tree root2) { return merge(root1, root2); }
