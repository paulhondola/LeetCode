#define MAX_LEN 100
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str, int size) {
  int i = 0, j = size - 1;

  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

char *convertToBase7(int num) {
  char *base7 = (char *)malloc(MAX_LEN);

  if (num == 0) {
    base7[0] = '0';
    base7[1] = '\0';
    return base7;
  }

  bool isNegative = false;

  if (num < 0) {
    isNegative = true;
    num = -num;
  }

  int index = 0;

  // start from the end of the string, then reverse it

  while (num) {
    base7[index++] = num % 7 + '0';
    num /= 7;
  }

  if (isNegative) {
    base7[index++] = '-';
  }

  base7[index] = '\0';

  // reverse the string

  reverseString(base7, index);

  return base7;
}

int main() {
  int num = -7;
  char *base7 = convertToBase7(num);
  printf("%s\n", base7);
  return 0;
}
