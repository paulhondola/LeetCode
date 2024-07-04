#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {

  uint32_t reversed = 0, mask = 1, size = sizeof(n) * 8 - 1;

  for (uint32_t i = 0; i < size; i++) {
    if (n & mask) {
      reversed |= 1U << (size - i);
    }
    mask <<= 1;
  }

  return reversed;
}

uint32_t binaryToDecimal(uint32_t n) {
  uint32_t decimal = 0, base = 1, rem = 0;

  while (n) {
    rem = n % 10;
    decimal += rem * base;
    n /= 10;
    base *= 2;
  }

  return decimal;
}

void showBits(uint32_t n) {

  int size = sizeof(n) * 8;
  uint32_t mask = 1 << (size - 1);

  while (mask) {
    printf("%d", (n & mask) ? 1 : 0);
    mask >>= 1;
  }
}

int main() {
  uint32_t n = 0b10100101000001111010011100;
  showBits(n);

  printf("\n\nReversed bits: %u\n", reverseBits(n));
  return 0;
}
