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

node add_node(node list, int val) {
  if (list == NULL) {
    list = init_node(val);
    return list;
  }

  node new_node = init_node(val);

  node current = list;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;

  return list;
}

void print_list(node list1) {
  node current = list1;
  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}

node addTwoNumbers(node l1, node l2) {
  if (l1 == NULL && l2 == NULL)
    return NULL;

  if (l1 == NULL)
    return l2;

  if (l2 == NULL)
    return l1;

  node sum_list = NULL;
  int carry = 0;

  while (l1 != NULL && l2 != NULL) {
    int sum = l1->val + l2->val + carry;
    carry = sum / 10;
    sum_list = add_node(sum_list, sum % 10);
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != NULL) {
    int sum = l1->val + carry;
    carry = sum / 10;
    sum_list = add_node(sum_list, sum % 10);
    l1 = l1->next;
  }

  while (l2 != NULL) {
    int sum = l2->val + carry;
    carry = sum / 10;
    sum_list = add_node(sum_list, sum % 10);
    l2 = l2->next;
  }

  if (carry)
    sum_list = add_node(sum_list, carry);

  return sum_list;
}

int main(void) {
  node list1 = NULL;
  list1 = add_node(list1, 2);
  list1 = add_node(list1, 4);
  list1 = add_node(list1, 6);

  node list2 = NULL;
  list2 = add_node(list2, 1);
  list2 = add_node(list2, 2);
  list2 = add_node(list2, 5);

  node sum_list = addTwoNumbers(list1, list2);

  print_list(list1);
  print_list(list2);
  print_list(sum_list);

  return 0;
}
