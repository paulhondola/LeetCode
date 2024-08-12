

int *sortArrayByParityII(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;

  int even_index = 0, odd_index = 1;

  while (even_index < numsSize && odd_index < numsSize) {
    if (nums[even_index] % 2 == 0)
      even_index += 2;
    else if (nums[odd_index] % 2 == 1)
      odd_index += 2;
    else {
      int temp = nums[even_index];
      nums[even_index] = nums[odd_index];
      nums[odd_index] = temp;
      even_index += 2;
      odd_index += 2;
    }
  }

  return nums;
}

/*
int *sortArrayByParityII(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *result = (int *)malloc(sizeof(int) * numsSize);

  int even_index = 0, odd_index = 1;

  for (int i = 0; i < numsSize; i++)
    if (nums[i] % 2)
      result[odd_index] = nums[i], odd_index += 2;
    else
      result[even_index] = nums[i], even_index += 2;

  return result;
}
*/
