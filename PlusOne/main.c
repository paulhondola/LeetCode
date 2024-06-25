#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {

  // The number of digits in the result will be the same as the input
  // (with the exception of the case where the first digit is 9 and the result
  // has one more digit)
  int *result = malloc(sizeof(int) * digitsSize);

  if (result == NULL)
    return NULL;

  int carry = 1;

  for (int i = digitsSize - 1; i >= 0; i--) {
    result[i] = (digits[i] + carry) % 10;
    carry = (digits[i] + carry) / 10;
  }

  if (carry) {
    result = realloc(result, sizeof(int) * (digitsSize + 1));

    if (result == NULL)
      return NULL;

    // shift all elements to the right

    for (int i = digitsSize; i > 0; i--) {
      result[i] = result[i - 1];
    }

    result[0] = 1;
    digitsSize++;
  }

  (*returnSize) = digitsSize;

  return result;
}

int main(void) {
  int digits[] = {1, 0, 0, 0, 0};
  int digitsSize = sizeof(digits) / sizeof(*digits);
  int return_size = 0;

  int *result = plusOne(digits, digitsSize, &return_size);

  for (int i = 0; i < return_size; i++) {
    printf("%d ", result[i]);
  }

  return 0;
}
