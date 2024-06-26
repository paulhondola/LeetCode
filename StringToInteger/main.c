#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int MAX_INT = 2147483647;
const int MIN_INT = -2147483648;

int myAtoi(char *s) {

  int index = 0;
  while (1) {
    if (s[index] == '-' || s[index] == '+' || isdigit(s[index]))
      break;

    if (!isdigit(s[index]) && s[index] != ' ')
      return 0;

    if (s[index] == ' ')
      index++;
  }

  long long int number = 0;
  int sign = 1;

  int len = strlen(s);

  if (s[index] == '-') {
    sign = -1;
  } else if (s[index] == '+') {
    sign = 1;
  } else {
    number = number * 10 + (s[index] - '0');
  }

  for (int i = index + 1; i < len; i++) {
    if (!isdigit(s[i]))
      break;

    number = number * 10 + (s[i] - '0');

    if (number > MAX_INT)
      return sign == 1 ? MAX_INT : MIN_INT;
  }

  number *= sign;

  if (number > MAX_INT) {
    return MAX_INT;
  } else if (number < MIN_INT) {
    return MIN_INT;
  } else {
    return number;
  }
}

int main() {
  char s[] = "     -495 53557997";
  printf("%d\n", myAtoi(s));
  return 0;
}
