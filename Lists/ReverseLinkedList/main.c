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

node reverseList(node head) {

  node new = NULL;

  while (head != NULL) {
    node temp = head->next;
    head->next = new;
    new = head;
    head = temp;
  }

  return new;
}

int main(void) {

  node list = init_node(1);
  list->next = init_node(2);
  list->next->next = init_node(3);
  list->next->next->next = init_node(4);
  list->next->next->next->next = init_node(5);

  print_list(list);

  list = reverseList(list);
  print_list(list);

  return 0;
}
