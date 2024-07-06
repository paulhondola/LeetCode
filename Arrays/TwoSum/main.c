#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Element;

int compare(const void *a, const void *b) {
  return ((Element *)a)->value - ((Element *)b)->value;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int sum = 0;
  Element arr[numsSize];
  int *result = (int *)malloc(2 * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    arr[i].value = nums[i];
    arr[i].index = i;
  }

  qsort(arr, numsSize, sizeof(Element), compare);

  int left = 0;
  int right = numsSize - 1;

  while (left < right) {
    sum = arr[left].value + arr[right].value;

    if (sum == target) {
      result[0] = arr[left].index;
      result[1] = arr[right].index;
      *returnSize = 2;
      return result;
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  *returnSize = 0;
  return NULL;
}

int main(void) {
  Element arr[] = {{3, 0}, {1, 1}, {2, 2}, {4, 3}};
  int n = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, n, sizeof(Element), compare);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i].value);
  }

  return 0;
}
