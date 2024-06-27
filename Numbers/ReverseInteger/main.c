#include <stdio.h>

const int MAX_INT = 2147483647;
const int MIN_INT = -2147483648;
const int ERR = 0;

int reverse_positive(int x) {
  int reversed = 0;
  while (x > 0) {
    if (reversed > MAX_INT / 10)
      return ERR;
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }
  return reversed;
}

int reverse_negative(int x) {
  int reversed = 0;
  while (x < 0) {
    if (reversed < MIN_INT / 10)
      return ERR;
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }
  return reversed;
}

int reverse(int x) {
  if (x == 0)
    return 0;
  else if (x > 0) {
    return reverse_positive(x);
  } else {
    return reverse_negative(x);
  }
}

int main(void) {
  int x = 1534236469;
  printf("Reversed number: %d\n", reverse(x));
}
