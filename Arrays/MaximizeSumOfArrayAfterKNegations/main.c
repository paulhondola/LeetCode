#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int arraySum(int *nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
  }
  return sum;
}

int largestSumAfterKNegations(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), comparator);

  int count = 0;
  while (count < numsSize && nums[count] < 0 && count < k) {
    nums[count] = -nums[count];
    count++;
  }

  if (count == k)
    return arraySum(nums, numsSize);

  qsort(nums, numsSize, sizeof(int), comparator);

  if ((k - count) % 2)
    nums[0] = -nums[0];

  return arraySum(nums, numsSize);
}

int main(void) {
  int nums[] = {-4, -2, -3};
  int numsSize = 3;
  int k = 4;

  int result = largestSumAfterKNegations(nums, numsSize, k);

  printf("Result: %d\n", result);
  return 0;
}
