#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicateZeros(int *arr, int arrSize) {
  int *copy = malloc(sizeof(int) * arrSize);

  int j = 0;
  for (int i = 0; i < arrSize && j < arrSize; i++) {
    if (!arr[i]) {
      copy[j++] = 0;
      if (j < arrSize)
        copy[j++] = 0;
    } else {
      copy[j++] = arr[i];
    }
  }

  for (int i = 0; i < arrSize; i++) {
    arr[i] = copy[i];
  }

  free(copy);
}

// Main function to test the gcdOfStrings function
int main() {

  int nums[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int numsSize = 8;

  duplicateZeros(nums, numsSize);

  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }

  return 0;
}
