#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i])
      nums[count++] = nums[i];
  }

  while (count < numsSize) {
    nums[count++] = 0;
  }
}
