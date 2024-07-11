#include <stdio.h>
#include <stdlib.h>
void showBits(int number) {
  unsigned int mask = 1U << 31;

  for (int i = 1; i <= 32; i++) {
    putchar(number & mask ? '1' : '0');
    number <<= 1;
  }

  putchar('\n');
}

int findComplement(int num) {
  unsigned int mask = 0;

  unsigned int temp = num;

  while (temp) {
    mask <<= 1;
    mask |= 1;
    temp >>= 1;
  }

  return num ^ mask;
}

int main(void) {

  int n = 5;
  showBits(n);
  int complement = findComplement(n);
  showBits(complement);
  printf("%d\n", complement);

  return 0;
}
