#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *licenseKeyFormatting(char *s, int k) {
  int len = strlen(s);
  char *formatted = malloc(len);
  char *letters = calloc(len, sizeof(char));

  int lettersIndex = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (s[i] != '-') {
      letters[lettersIndex++] = toupper(s[i]);
    }
  }

  for (int i = 0; i < lettersIndex; i++)
    printf("%c", letters[i]);

  printf("\n");

  int formattedIndex = 0;
  int firstGroup = lettersIndex % k;

  if (firstGroup != 0) {
    for (int i = 0; i < firstGroup; i++) {
      formatted[formattedIndex++] = letters[i];
    }
    if (firstGroup != lettersIndex) {
      formatted[formattedIndex++] = '-';
    }
  }

  for (int i = firstGroup; i < lettersIndex; i++) {
    if ((i - firstGroup) % k == 0 && i != firstGroup) {
      formatted[formattedIndex++] = '-';
    }
    formatted[formattedIndex++] = letters[i];
  }

  return formatted;
}

int main(void) {
  char *s = "5F3Z-2e-9-w";

  char *formatted = licenseKeyFormatting(s, 5);

  printf("%s\n", formatted);

  return 0;
}
