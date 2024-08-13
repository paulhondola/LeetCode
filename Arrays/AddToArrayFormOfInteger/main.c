#include <stdio.h>
#include <stdlib.h>

int *addToArrayForm(int *num, int numSize, int k, int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * (numSize + 1));
  *returnSize = numSize + 1;
  int carry = 0;

  for (int i = numSize - 1; i >= 0; i--) {
    int sum = num[i] + k % 10 + carry;
    k /= 10;
    result[i + 1] = sum % 10;
    carry = sum / 10;
  }

  if (carry) {
    result[0] = carry;
  } else {
    result++;
    (*returnSize)--;
  }

  return result;
}

int main() {

  int num[] = {2, 1, 5};
  int numSize = 3;
  int k = 806;
  int returnSize = 0;
  int *result = addToArrayForm(num, numSize, k, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }

  // free(result);

  return 0;
}
