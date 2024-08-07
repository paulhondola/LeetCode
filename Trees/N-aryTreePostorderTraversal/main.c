#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
  int val;
  int numChildren;
  struct Node **children;
};

typedef struct Node Node;

// Function to create a new node
Node *createNode(int val, int numChildren) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->numChildren = numChildren;
  newNode->children = (Node **)malloc(numChildren * sizeof(Node *));
  return newNode;
}

// Helper function to perform the preorder traversal
void traverse(Node *node, int *result, int *returnSize) {
  if (node == NULL) {
    return;
  }

  for (int i = 0; i < node->numChildren; i++) {
    traverse(node->children[i], result,
             returnSize); // Recursively visit each child
  }

  result[(*returnSize)++] = node->val; // Visit the root node
}

// Function to perform the preorder traversal
int *postorder(Node *root, int *returnSize) {
  *returnSize = 0;
  int *result = (int *)malloc(
      1000 * sizeof(int)); // Allocate a large enough array for results
  traverse(root, result, returnSize);
  return result;
}

// Helper function to free the nodes
void freeTree(Node *root) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < root->numChildren; i++) {
    freeTree(root->children[i]);
  }
  free(root->children);
  free(root);
}

int main() {
  // Example N-ary tree:
  //        1
  //      / | \
    //     3  2  4
  //    / \
    //   5   6

  // Creating the tree nodes
  Node *node5 = createNode(5, 0);
  Node *node6 = createNode(6, 0);
  Node *node3 = createNode(3, 2);
  node3->children[0] = node5;
  node3->children[1] = node6;
  Node *node2 = createNode(2, 0);
  Node *node4 = createNode(4, 0);
  Node *root = createNode(1, 3);
  root->children[0] = node3;
  root->children[1] = node2;
  root->children[2] = node4;

  // Performing preorder traversal
  int returnSize;
  int *result = postorder(root, &returnSize);

  // Printing the result
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(result);
  freeTree(root);

  return 0;
}
