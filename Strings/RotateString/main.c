#include <stdbool.h>

void rotate(char *s) {
  int len = strlen(s);
  char tmp = s[0];
  for (int i = 0; i < len - 1; i++) {
    s[i] = s[i + 1];
  }

  s[len - 1] = tmp;
}

bool rotateString(char *s, char *goal) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (strcmp(s, goal) == 0) {
      return true;
    }
    rotate(s);
  }

  return false;
}
