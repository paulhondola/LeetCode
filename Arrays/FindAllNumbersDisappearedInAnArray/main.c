/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q) { return (*(int *)p - *(int *)q); }

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
  qsort(nums, numsSize, sizeof(int), comparator);

  int *missing = (int *)malloc(sizeof(int) * numsSize);

  int index = 0;
  int missing_count = 0;

  if (nums[0] != 1) {
    missing[missing_count] = 1;
    missing_count++;
    index++;
  }

  for (int i = 1; i <= numsSize; i++) {
    if (nums[index - 1] == nums[index]) {
      index++;
      i--;
      continue;
    }

    if (nums[index] != i) {
      missing[missing_count] = i;
      missing_count++;
    } else {
      index++;
    }
  }

  *returnSize = missing_count;

  return missing;
}

int main(void) {
  int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  int returnSize = 0;

  int *res = findDisappearedNumbers(nums, numsSize, &returnSize);

  for (int i = 0; i < returnSize; i++)
    printf("%d ", res[i]);

  return 0;
}
