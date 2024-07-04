#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convertToLetter(int n) { return (char)(n + 64); }

char *convertString(char *string) {

  int len = strlen(string);
  char *new = malloc(len + 1);

  int index = 0;
  for (int i = 0; i <= len; i++)
    if (string[i] != '0')
      new[index++] = string[i];

  free(string);

  return new;
}

char *convertToTitle(int columnNumber) {

  const int MAXSIZE = 10;

  char *title = malloc(MAXSIZE);

  for (int i = 0; i < MAXSIZE - 1; i++)
    title[i] = '0';

  title[MAXSIZE - 1] = '\0';

  int index = MAXSIZE - 2;

  while (columnNumber) {
    int remainder = columnNumber % 26;
    if (remainder == 0) {
      title[index] = 'Z';
      columnNumber = columnNumber / 26 - 1;
    } else {
      title[index] = convertToLetter(remainder);
      columnNumber /= 26;
    }

    index--;
  }

  return convertString(title);
}

int main(void) {

  char *title = convertToTitle(52);

  printf("%s\n", title);

  return 0;
}
