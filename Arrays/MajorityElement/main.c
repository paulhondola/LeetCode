#include <stdio.h>

int majorityElement(int nums[], int numsSize) {
  int ans = 0;
  int cnt = 0;

  for (int i = 0; i < numsSize; i++) {
    if (cnt == 0) {
      ans = nums[i];
    }

    if (nums[i] == ans) {
      cnt++;
    } else {
      cnt--;
    }
  }
  return ans;
}

int main(void) {
  int nums[] = {3, 2, 3, 3, 2, 4, 4, 4, 4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  int ans = majorityElement(nums, numsSize);

  printf("%d\n", ans);

  return 0;
}
