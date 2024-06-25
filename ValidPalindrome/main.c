#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_string(char *s) {
  int len = strlen(s);
  char *result = (char *)malloc(sizeof(char) * (len + 1));
  int index = 0;

  for (int i = 0; i < len; i++)
    if (isalnum(s[i]))
      result[index++] = tolower(s[i]);

  result[index] = '\0';

  return result;
}

bool isPalindrome(char *s) {
  char *str = convert_string(s);

  printf("%s", str);

  int left = 0;
  int right = strlen(str) - 1;

  while (1) {
    if (left >= right) {
      free(str);
      return true;
    }

    if (str[left] != str[right]) {
      free(str);
      return false;
    }

    left++;
    right--;
  }

  free(str);

  return true;
}

int main(void) {
  printf("%d\n", isPalindrome("a"));
  return 0;
}
