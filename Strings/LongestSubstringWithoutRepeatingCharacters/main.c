#include <stdio.h>
#include <string.h>

int checkRepeating(char *s, int start, int end) {
  for (int i = start; i < end; i++)
    if (s[i] == s[end])
      return 1;
  return 0;
}

int lengthOfLongestSubstring(char *s) {
  int current_length = 1;
  int max_length = 0;

  int len = strlen(s);

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (checkRepeating(s, i, j))
        break;
      else
        current_length++;
    }

    if (current_length > max_length)
      max_length = current_length;

    current_length = 1;
  }

  return max_length;
}

int main(void) {
  char s[] = "abcabcbb";
  int result = lengthOfLongestSubstring(s);

  printf("%d", result);

  return 0;
}
