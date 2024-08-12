int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *result = (int *)malloc(sizeof(int) * numsSize);

  int left = 0, right = numsSize - 1;

  for (int i = 0; i < numsSize; i++)
    if (nums[i] % 2)
      result[right--] = nums[i];
    else
      result[left++] = nums[i];

  return result;
}
