#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Definition for the queue node.
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

// Queue structure for level order traversal.
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Function to create a new binary tree node.
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node.
struct QueueNode* createQueueNode(struct TreeNode* node) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->node = node;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// Function to create a queue.
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty.
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add a node to the queue.
void enqueue(struct Queue* queue, struct TreeNode* node) {
    struct QueueNode* newQueueNode = createQueueNode(node);
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newQueueNode;
    } else {
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }
}

// Function to remove a node from the queue.
struct TreeNode* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    struct TreeNode* node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

// Function to get the right side view of the binary tree.
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);
    int* rightView = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    while (!isQueueEmpty(queue)) {
        int levelSize = 0;
        struct Queue* tempQueue = createQueue();

        while (!isQueueEmpty(queue)) {
            struct TreeNode* node = dequeue(queue);
            if (node->left) enqueue(tempQueue, node->left);
            if (node->right) enqueue(tempQueue, node->right);
            levelSize++;
            if (isQueueEmpty(queue)) {
                rightView[*returnSize] = node->val;
                (*returnSize)++;
            }
        }

        free(queue);
        queue = tempQueue;
    }

    free(queue);
    return rightView;
}

// Helper function to free the tree nodes.
void freeTree(struct TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Helper function to print the right side view.
void printRightSideView(int* rightView, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", rightView[i]);
    }
    printf("\n");
}

// Main function for testing.
int main() {
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->right = createTreeNode(5);
    root->right->right = createTreeNode(4);

    int returnSize;
    int* rightView = rightSideView(root, &returnSize);
    printRightSideView(rightView, returnSize);

    free(rightView);
    freeTree(root);

    return 0;
}
