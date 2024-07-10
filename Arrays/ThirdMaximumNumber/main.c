#include <limits.h>

int thirdMax(int *nums, int numsSize) {
  long long int first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

  for (int i = 0; i < numsSize; i++) {

    if (first == nums[i] || second == nums[i] || third == nums[i])
      continue;

    if (first < nums[i]) {
      third = second;
      second = first;
      first = nums[i];
    } else if (second < nums[i]) {
      third = second;
      second = nums[i];
    } else if (third < nums[i]) {
      third = nums[i];
    }
  }

  if (first == LLONG_MIN)
    return INT_MIN;

  if (second == LLONG_MIN)
    return first;

  if (third == LLONG_MIN)
    return first;

  return third;
}
