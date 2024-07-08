#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode *node;

node init_node(int val) {
  node new_node = (node)malloc(sizeof(struct ListNode));
  new_node->val = val;
  new_node->next = NULL;

  return new_node;
}

void print_list(node head) {
  node current = head;

  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }

  printf("\n");
}

node copyReverseList(node head) {
  node new = NULL;
  node current = head;

  while (current != NULL) {
    node temp = init_node(current->val);
    temp->next = new;
    new = temp;
    current = current->next;
  }

  return new;
}

bool isPalindrome(node head) {

  node reversed = copyReverseList(head);

  node current = head;

  while (current != NULL) {
    if (current->val != reversed->val) {
      return false;
    }

    current = current->next;
    reversed = reversed->next;
  }

  return true;
}

int main(void) {

  node list = init_node(1);
  list->next = init_node(2);
  list->next->next = init_node(3);
  list->next->next->next = init_node(3);
  list->next->next->next->next = init_node(2);
  list->next->next->next->next->next = init_node(2);
  // list->next->next->next->next->next->next = init_node(6);

  // print_list(list);

  printf("%d\n", isPalindrome(list));

  // print_list(list);

  return 0;
}
