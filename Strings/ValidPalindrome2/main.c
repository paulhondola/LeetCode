#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool checkSimplePalindrom(char *s) {
  int len = strlen(s);
  int left = 0, right = len - 1;

  while (left < right) {
    if (s[left] != s[right])
      return false;

    left++;
    right--;
  }

  return true;
}

bool validPalindrome(char *s) {

  int len = strlen(s);

  if (checkSimplePalindrom(s))
    return true;

  int left, right;
  bool flag = true;

  for (int i = 0; i < len; i++) {

    flag = true;
    left = 0;
    right = len - 1;

    while (left < right) {
      if (left == i) {
        left++;
        continue;
      } else if (right == i) {
        right--;
        continue;
      }

      if (s[left] != s[right]) {
        flag = false;
        break;
      }

      left++;
      right--;
    }

    if (flag)
      return true;
  }

  return false;
}

int main(void) {
  char *s = "dadca";

  if (validPalindrome(s))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
