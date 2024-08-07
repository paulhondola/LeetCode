int dominantIndex(int *nums, int numsSize) {
  int second_max = 0, max = 0, max_index = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > max) {
      second_max = max;
      max = nums[i];
      max_index = i;
    } else if (nums[i] > second_max) {
      second_max = nums[i];
    }
  }

  if (max >= 2 * second_max) {
    return max_index;
  } else {
    return -1;
  }
}
