#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int findTilt_aux(struct TreeNode *root, int *tilt) {
  if (root == NULL) {
    return 0;
  }

  int left = findTilt_aux(root->left, tilt);
  int right = findTilt_aux(root->right, tilt);

  *tilt += abs(left - right);

  return left + right + root->val;
}

int findTilt(struct TreeNode *root) {
  int tilt = 0;
  findTilt_aux(root, &tilt);
  return tilt;
}
