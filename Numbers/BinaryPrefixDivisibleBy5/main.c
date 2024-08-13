#include <stdbool.h>
#include <stdlib.h>

bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize) {
  bool *result = (bool *)malloc(numsSize * sizeof(bool));
  *returnSize = numsSize;

  int remainder = 0;

  for (int i = 0; i < numsSize; i++) {
    remainder = (remainder * 2 + nums[i]) % 5;
    result[i] = (remainder == 0);
  }

  return result;
}
