int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int max_seq = 0, current_seq = 0;

  current_seq = nums[0];

  for (int i = 1; i < numsSize; i++) {
    if (nums[i])
      current_seq++;
    else {
      if (current_seq > max_seq)
        max_seq = current_seq;
      current_seq = 0;
    }
  }

  if (current_seq > max_seq)
    max_seq = current_seq;

  return max_seq;
}
