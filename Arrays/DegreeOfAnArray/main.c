#define MAX_VAL 50000

int findShortestSubArray(int *nums, int numsSize) {
  int count[MAX_VAL] = {0}, first[MAX_VAL] = {0}, last[MAX_VAL] = {0};
  int degree = 0, len = numsSize;

  for (int i = 0; i < numsSize; i++) {
    if (count[nums[i]] == 0) {
      first[nums[i]] = i;
    }
    last[nums[i]] = i;
    count[nums[i]]++;
    degree = count[nums[i]] > degree ? count[nums[i]] : degree;
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (count[i] == degree) {
      len = len < (last[i] - first[i] + 1) ? len : (last[i] - first[i] + 1);
    }
  }

  return len;
}
