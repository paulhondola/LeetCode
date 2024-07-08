/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4294967298
#define MAX_RANGES 20
#define STR_SIZE 5

char **allocMatrix() {
  char **result = (char **)malloc(sizeof(char *) * MAX_RANGES);

  for (int i = 0; i < MAX_RANGES; i++) {
    result[i] = (char *)malloc(sizeof(char) * STR_SIZE);
  }

  return result;
}

char **summaryRanges(int *nums, int numsSize, int *returnSize) {

  char **result = allocMatrix();

  *returnSize = 0;
  result[*returnSize][0] = nums[0] + '0';

  for (int i = 1; i < numsSize; i++) {
    // diff = 1 -> continue
    if (nums[i] - nums[i - 1] == 1) {
      result[*returnSize][1] = '-';
      result[*returnSize][2] = '>';
      result[*returnSize][3] = nums[i] + '0';
      result[*returnSize][4] = '\0';
    } else {
    }
  }

  return result;
}
