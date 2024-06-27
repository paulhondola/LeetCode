#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int threeSumClosest(int *nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(int), compare);

  int closest_sum = INT_MAX;
  int min_diff = INT_MAX;

  for (int i = 0; i < numsSize - 2; i++) {
    int left = i + 1;
    int right = numsSize - 1;

    while (left < right) {
      int current_sum = nums[i] + nums[left] + nums[right];
      int diff = abs(current_sum - target);

      if (diff == 0) {
        return current_sum; // Found exact match
      }

      if (diff < min_diff) {
        min_diff = diff;
        closest_sum = current_sum;
      }

      if (current_sum < target) {
        left++;
      } else {
        right--;
      }
    }
  }

  return closest_sum;
}

int main() {
  int nums[] = {-1, 2, 1, -4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int target = 1;

  int result = threeSumClosest(nums, numsSize, target);
  printf("The sum closest to target %d is %d\n", target, result);

  return 0;
}
