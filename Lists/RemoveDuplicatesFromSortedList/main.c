#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode *node;

node init_node(int val) {
  node n = (node)malloc(sizeof(struct ListNode));

  if (n == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  n->val = val;
  n->next = NULL;
  return n;
}

node add_node(node head, int val) {
  node new = init_node(val);
  new->next = head;
  head = new;
  return head;
}

node deleteDuplicates(node head) {
    if (head == NULL) {
        return NULL;
    }

    node current = head;
    node next = head->next;

    while (next != NULL) {
        if (current->val == next->val) {
        current->next = next->next;
        free(next);
        next = current->next;
        } else {
        current = next;
        next = next->next;
        }
    }
    return head;
}

void print_list(node head) {
  node current = head;

  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }

  printf("\n");
}

int main(void) {

  node list = init_node(1);
  list = add_node(list, 2);
  list = add_node(list, 3);
  list = add_node(list, 3);
  list = add_node(list, 4);
  list = add_node(list, 4);

  list = deleteDuplicates(list);

  print_list(list);

  return 0;
}
