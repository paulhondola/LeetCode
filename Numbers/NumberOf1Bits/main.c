#include <stdint.h>

int hammingWeight(int n) {
  uint32_t size = sizeof(n) * 8, mask = 1U << (size - 1);

  int count = 0;
  while (mask) {
    if (n & mask) {
      count++;
    }
    mask >>= 1;
  }
  return count;
}

int hammingWeight2(int n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
