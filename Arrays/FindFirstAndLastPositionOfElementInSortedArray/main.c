#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int *nums, int target, int left, int right) {
  int mid = (left + right) / 2;
  if (nums[mid] == target)
    return mid;
  if (left == right)
    return -1;
  if (nums[mid] < target)
    return binarySearch(nums, target, mid + 1, right);
  return binarySearch(nums, target, left, mid - 1);
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
  int *result = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;

  if (numsSize == 0) {
    result[0] = -1;
    result[1] = -1;
    return result;
  }

  if (target < nums[0] || target > nums[numsSize - 1]) {
    result[0] = -1;
    result[1] = -1;
    return result;
  }

  const int index = binarySearch(nums, target, 0, numsSize - 1);

  if (index == -1) {
    result[0] = -1;
    result[1] = -1;
    return result;
  }

  int left_index = index, right_index = index;

  while (left_index > 0 && nums[left_index - 1] == target)
    left_index--;

  while (right_index < numsSize - 1 && nums[right_index + 1] == target)
    right_index++;

  result[0] = left_index;
  result[1] = right_index;

  return result;
}

// Main function to test the gcdOfStrings function
int main() {

  int nums[] = {5, 7, 7, 8, 8, 10};
  int numsSize = 6;
  int target = 6;

  int returnSize;

  int *result = searchRange(nums, numsSize, target, &returnSize);

  printf("%d %d\n", result[0], result[1]);

  return 0;
}
