#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char *columnTitle) {
  int len = strlen(columnTitle);
  int power = 1;
  int title = 0;

  for (int i = 0; i < len; i++)
    title = title * 26 + (columnTitle[i] - 'A' + 1);

  return title;
}
