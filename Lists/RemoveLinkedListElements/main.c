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

node removeElements(node head, int val) {

  if (head == NULL)
    return NULL;

  // remove the first element if it is equal to val
  while (head->val == val && head->next != NULL) {
    node temp = head;
    head = head->next;
    free(temp);
  }

  if (head->val == val) {
    free(head);
    return NULL;
  }

  // remove the rest of the elements
  node current = head;
  while (current != NULL && current->next != NULL) {
    if (current->next->val == val) {
      node temp = current->next;
      current->next = current->next->next;
      free(temp);
    } else {
      current = current->next;
    }
  }

  return head;
}

int main(void) {

  node list = init_node(6);
  list->next = init_node(6);
  list->next->next = init_node(6);
  list->next->next->next = init_node(6);
  list->next->next->next->next = init_node(6);
  list->next->next->next->next->next = init_node(6);
  list->next->next->next->next->next->next = init_node(6);

  print_list(list);

  list = removeElements(list, 6);

  // print_list(list);

  return 0;
}
