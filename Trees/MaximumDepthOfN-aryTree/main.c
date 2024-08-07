#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
typedef struct Node {
  int val;
  int numChildren;
  struct Node **children;
} Node;

// Function to create a new node
Node *createNode(int val, int numChildren) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->numChildren = numChildren;
  newNode->children = (Node **)malloc(numChildren * sizeof(Node *));
  return newNode;
}

// Recursive function to find the maximum depth
int maxDepth(Node *root) {
  if (root == NULL) {
    return 0;
  }

  if (root->numChildren == 0) {
    return 1;
  }

  int max_child_depth = 0;
  for (int i = 0; i < root->numChildren; i++) {
    int child_depth = maxDepth(root->children[i]);
    if (child_depth > max_child_depth) {
      max_child_depth = child_depth;
    }
  }

  return max_child_depth + 1;
}

// Helper function to free the tree nodes
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

  // Finding the maximum depth
  printf("Maximum Depth: %d\n", maxDepth(root)); // Output: 3

  // Free the allocated memory
  freeTree(root);

  return 0;
}
