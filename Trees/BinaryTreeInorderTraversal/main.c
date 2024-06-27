#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *tree;

int *inorderTraversal(tree root, int *returnSize) {

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;

    tree *stack = (tree *)malloc(100 * sizeof(tree));
    int top = -1;

    tree current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        result[(*returnSize)++] = current->val;
        current = current->right;
    }

    free(stack);
    return result;

}
