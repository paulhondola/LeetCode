/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findErrorNums(int *nums, int numsSize, int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * 2);
  *returnSize = 2;

  int freq[10001] = {0};

  for (int i = 0; i < numsSize; i++)
    freq[nums[i]]++;

  for (int i = 1; i <= numsSize; i++)
    if (freq[i] == 2)
      result[0] = i;
    else if (freq[i] == 0)
      result[1] = i;

  return result;
}

/*
int *findErrorNums(int *nums, int numsSize, int *returnSize) {
 int sum = 0;

 int *result = (int *)malloc(sizeof(int) * 2);

 for (int i = 0; i < numsSize; i++) {
   sum += abs(nums[i]);
   if (nums[abs(nums[i]) - 1] < 0) {
     result[0] = abs(nums[i]);
   } else {
     nums[abs(nums[i]) - 1] *= -1;
   }
 }

 result[1] = (1 + numsSize) * numsSize / 2 - sum + result[0];

 *returnSize = 2;

 return result;
}
*/
