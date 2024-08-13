int repeatedNTimes(int *nums, int numsSize) {
  // Create a hash set to store seen elements
  int seen[10000] = {0}; // Array to simulate a set since elements are small

  // Traverse the array
  for (int i = 0; i < numsSize; i++) {
    if (seen[nums[i]] == 1) {
      return nums[i]; // The repeated element found
    }
    seen[nums[i]] = 1; // Mark element as seen
  }

  return -1; // Return -1 if not found, though this line should never be reached
}
