int b_search(int *nums, int left, int right, int target) {
  int mid = (left + right) / 2;
  if (left > right)
    return -1;

  if (nums[mid] == target)
    return mid;
  else if (nums[mid] < target)
    return b_search(nums, mid + 1, right, target);
  else
    return b_search(nums, left, mid - 1, target);
}

int search(int *nums, int numsSize, int target) {
  return b_search(nums, 0, numsSize - 1, target);
}
