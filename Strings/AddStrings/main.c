#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addStrings(char *num1, char *num2) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);

  int res_len = len1 > len2 ? len1 : len2;

  char *res = (char *)malloc(sizeof(char) * (res_len + 1));

  res[res_len] = 0;
  int carry = 0;
  int i = res_len - 1;

  while (len1 > 0 || len2 > 0) {
    int n1 = len1 > 0 ? num1[--len1] - '0' : 0;
    int n2 = len2 > 0 ? num2[--len2] - '0' : 0;

    int sum = n1 + n2 + carry;
    carry = sum / 10;
    res[i--] = sum % 10 + '0';
  }

  if (carry) {
    res = (char *)realloc(res, sizeof(char) * (res_len + 2));

    for (int i = res_len; i >= 0; i--)
      res[i + 1] = res[i];

    res[0] = carry + '0';
  }

  return res;
}

int main(void) {
  char *num1 = "623";
  char *num2 = "456";

  char *res = addStrings(num1, num2);

  printf("%s\n", res);

  return 0;
}
