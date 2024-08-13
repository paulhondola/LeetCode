#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int *sortedNums = (int *)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

  int index = numsSize - 1, left = 0, right = numsSize - 1;

  while (left <= right) {
    int leftSquare = nums[left] * nums[left];
    int rightSquare = nums[right] * nums[right];

    if (leftSquare > rightSquare)
      sortedNums[index--] = leftSquare, left++;
    else
      sortedNums[index--] = rightSquare, right--;
  }

  return sortedNums;
}
int main() {

  int array[] = {-4, -1, 0, 3, 10};
  int returnSize;

  int *result = sortedSquares(array, 5, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }

  free(result);
  return 0;
}
