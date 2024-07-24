double findMaxAverage(int *nums, int numsSize, int k) {
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }
  double max = sum;
  for (int i = k; i < numsSize; i++) {
    sum += nums[i] - nums[i - k];
    if (sum > max) {
      max = sum;
    }
  }
  return max / k;
}
