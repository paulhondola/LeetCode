#include <stdbool.h>
#include <stdio.h>

bool hasAlternatingBits(int n) {
  int prev = n & 1; // Get the least significant bit
  n >>= 1;          // Shift right to process the next bit

  while (n > 0) {
    int current = n & 1; // Get the current least significant bit
    if (prev == current) {
      return false; // If two consecutive bits are the same, return false
    }
    prev = current; // Update prev to current
    n >>= 1;        // Shift right to process the next bit
  }

  return true; // All bits were alternating
}

int main(void) {
  printf("%d", hasAlternatingBits(10)); // Expected output: 1 (true)

  return 0;
}
