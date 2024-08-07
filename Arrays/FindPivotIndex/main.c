int pivotIndex(int *nums, int numsSize) {
  int left_sum = 0, right_sum = 0;

  for (int i = 0; i < numsSize; i++) {
    right_sum += nums[i];
  }

  for (int i = 0; i < numsSize; i++) {
    right_sum -= nums[i];
    if (left_sum == right_sum)
      return i;
    left_sum += nums[i];
  }

  return -1;
}
