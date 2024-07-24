int findLengthOfLCIS(int *nums, int numsSize) {
  int current_seq = 1, max_seq = 1;

  if (numsSize == 0) {
    return 0;
  }

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1]) {
      current_seq++;
    } else {
      if (current_seq > max_seq) {
        max_seq = current_seq;
      }
      current_seq = 1;
    }
  }

  if (current_seq > max_seq) {
    max_seq = current_seq;
  }

  return max_seq;
}
