#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char **operations, int operationsSize) {
  int stack[1001];
  int top = 0;

  for (int i = 0; i < operationsSize; i++) {
    if (operations[i][0] == '+') {
      if (top < 2)
        continue;
      stack[top] = stack[top - 1] + stack[top - 2];
      top++;
    } else if (operations[i][0] == 'D') {
      if (top < 1)
        continue;
      stack[top] = stack[top - 1] * 2;
      top++;
    } else if (operations[i][0] == 'C') {
      if (top < 1)
        continue;
      top--;
    } else {
      stack[top] = atoi(operations[i]);
      top++;
    }
  }

  int sum = 0;
  for (int i = 0; i < top; i++) {
    sum += stack[i];
  }

  return sum;
}
