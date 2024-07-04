#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode *node;

int getListLength(node head) {
  int length = 0;
  node iterator = head;
  while (iterator) {
    length++;
    iterator = iterator->next;
  }
  return length;
}

node getIntersectionNode(node headA, node headB) {

  int lenA = getListLength(headA);
  int lenB = getListLength(headB);

  node iteratorA = headA;
  node iteratorB = headB;

  for (int i = lenA; i < lenB; i++)
    iteratorB = iteratorB->next;
  for (int i = lenB; i < lenA; i++)
    iteratorA = iteratorA->next;

  while (iteratorA && iteratorB) {
    if (iteratorA == iteratorB)
      return iteratorA;
    iteratorA = iteratorA->next;
    iteratorB = iteratorB->next;
  }

  return NULL;
}

node addNode(int val) {
  node newNode = (node)malloc(sizeof(struct ListNode));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

void printList(node head) {
  node iterator = head;
  while (iterator) {
    printf("%d -> ", iterator->val);
    iterator = iterator->next;
  }
  printf("NULL\n");
}

int main(void) {
  node headA = addNode(4);
  headA->next = addNode(1);
  headA->next->next = addNode(8);
  headA->next->next->next = addNode(4);
  headA->next->next->next->next = addNode(5);

  node headB = addNode(5);
  headB->next = addNode(6);
  headB->next->next = addNode(1);
  headB->next->next->next = headA->next->next;

  node intersectionNode = getIntersectionNode(headA, headB);

  printList(intersectionNode);

  return 0;
}
