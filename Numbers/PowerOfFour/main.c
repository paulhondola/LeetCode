#include <stdbool.h>

bool isPowerOfFour(int n) {
  if (n == 0)
    return false;

  return (n & (n - 1)) == 0 && (n & 0x55555555);
}
