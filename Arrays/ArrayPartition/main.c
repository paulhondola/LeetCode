int comparatorAsc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int arrayPairSum(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), comparatorAsc);

  int sum = 0;

  for (int i = 0; i < numsSize; i += 2)
    sum += (nums[i] < nums[i + 1]) ? nums[i] : nums[i + 1];

  return sum;
}
