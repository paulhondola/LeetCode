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

void add_node(node list1, int val) {
  node new_node = init_node(val);

  if (list1 == NULL) {
    list1 = new_node;
    return;
  }

  node current = list1;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

void print_list(node list1) {
  node current = list1;
  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}

node mergeLists(node list1, node list2) {

  if (list1 == NULL && list2 == NULL)
    return NULL;

  if (list1 == NULL)
    return list2;

  if (list2 == NULL)
    return list1;

  node current1 = list1;
  node current2 = list2;

  node merged_list = NULL;

  if (current1->val < current2->val) {
    merged_list = init_node(current1->val);
    current1 = current1->next;
  } else {
    merged_list = init_node(current2->val);
    current2 = current2->next;
  }

  while (current1 != NULL && current2 != NULL) {
    if (current1->val < current2->val) {
      add_node(merged_list, current1->val);
      current1 = current1->next;
    } else {
      add_node(merged_list, current2->val);
      current2 = current2->next;
    }
  }

  while (current1 != NULL) {
    add_node(merged_list, current1->val);
    current1 = current1->next;
  }

  while (current2 != NULL) {
    add_node(merged_list, current2->val);
    current2 = current2->next;
  }

  return merged_list;
}

int main(void) {
  node list1 = init_node(0);
  add_node(list1, 2);
  add_node(list1, 4);
  add_node(list1, 6);

  node list2 = init_node(0);
  add_node(list2, 1);
  add_node(list2, 2);
  add_node(list2, 5);

  node merged_list = mergeLists(list1, list2);

  print_list(list1);
  print_list(list2);
  print_list(merged_list);

  return 0;
}
