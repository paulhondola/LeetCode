#include <stdbool.h>

bool validMountainArray(int *arr, int arrSize) {
  if (arrSize < 3)
    return false;

  int peak = 0;
  // check if the array is increasing
  for (peak = 1; peak < arrSize; peak++)
    if (arr[peak - 1] >= arr[peak])
      break;

  if (peak == 1 || peak == arrSize)
    return false;

  // check if the array is decreasing

  for (; peak < arrSize; peak++)
    if (arr[peak - 1] <= arr[peak])
      break;

  return peak == arrSize;
}

// sliding window approach

int validMountainArray2(int *arr, int arrSize) {
  int i = 0;
  int j = arrSize - 1;

  while (i + 1 < arrSize && arr[i] < arr[i + 1])
    i++;
  while (j > 0 && arr[j - 1] > arr[j])
    j--;

  return i > 0 && j < arrSize - 1 && i == j;
}
