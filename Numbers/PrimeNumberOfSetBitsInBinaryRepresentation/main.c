// 10^6 == 1000000
#include <stdbool.h>

int countBits(int num) {
  int count = 0;
  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

int countPrimeSetBits(int left, int right) {

  bool primes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                   0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                   0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};

  int count = 0;

  for (int i = left; i <= right; i++) {
    count += primes[countBits(i)];
  }

  return count;
}
