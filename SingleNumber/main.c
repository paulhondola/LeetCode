#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
  int result = 0;
  for (int i = 0; i < numsSize; i++) {
    result ^= nums[i];

    printf("%d\n", result);
  }

  return result;
}

int main(void) {
  int nums[] = {2, 1, 1};
  int numsSize = 3;
  int result = singleNumber(nums, numsSize);

  printf("%d", result);

  return 0;
}
