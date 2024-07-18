int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maximumProduct(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);

  // Calculate the product of the three largest numbers
  int maxProduct1 =
      nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];

  // Calculate the product of the two smallest numbers and the largest number
  int maxProduct2 = nums[0] * nums[1] * nums[numsSize - 1];

  // Return the maximum of the two calculated products
  return maxProduct1 > maxProduct2 ? maxProduct1 : maxProduct2;
}
