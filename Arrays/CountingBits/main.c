/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int *countBits(int n, int *returnSize) {
  int *arr = (int *)malloc(sizeof(int) * (n + 1));
  *returnSize = n + 1;

  arr[0] = 0;

  for (int i = 1; i <= n; i++) {
    arr[i] = arr[i >> 1] + (i & 1);
  }

  return arr;
}

int main(void) {
  int n = 5;
  int returnSize = 0;
  int *arr = countBits(n, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
