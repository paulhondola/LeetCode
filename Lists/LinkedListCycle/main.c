#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return false;
  }

  struct ListNode *slow = head;
  struct ListNode *fast = head->next;

  while (slow != fast) {
    if (fast == NULL || fast->next == NULL) {
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
  }

  return true;
}

// Helper function to create a new node
struct ListNode *createNode(int val) {
  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

// Test the function
int main() {
  // Create nodes
  struct ListNode *head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);

  // Create a cycle for testing
  head->next->next->next->next = head->next; // 4 -> 2 creates a cycle

  if (hasCycle(head)) {
    printf("The linked list has a cycle.\n");
  } else {
    printf("The linked list does not have a cycle.\n");
  }

  // Free allocated memory (Note: This won't work properly if there's a cycle)
  // In real applications, care should be taken to avoid memory leaks.
  // struct ListNode *temp;
  // while (head != NULL) {
  //     temp = head;
  //     head = head->next;
  //     free(temp);
  // }

  return 0;
}
