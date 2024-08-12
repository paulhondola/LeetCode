bool isMonotonic(int *nums, int numsSize) {

  if (numsSize == 1) {
    return true;
  }

  enum { ASC, DESC, NO } state = NO;

  int left = 1, right = numsSize - 2;

  while (left - 1 <= right + 1) {
    if (nums[left - 1] < nums[left]) {
      if (state == DESC)
        return false;
      state = ASC;
    } else if (nums[left - 1] > nums[left]) {
      if (state == ASC)
        return false;
      state = DESC;
    }

    if (nums[right] < nums[right + 1]) {
      if (state == DESC)
        return false;
      state = ASC;
    } else if (nums[right] > nums[right + 1]) {
      if (state == ASC)
        return false;
      state = DESC;
    }

    left++;
    right--;
  }

  return true;
}
