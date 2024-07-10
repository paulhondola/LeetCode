#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toHex(int num) {
  char *hex = (char *)calloc(9, sizeof(char));
  char *hex_map = "0123456789abcdef";

  unsigned int mask = 0;

  if (num == 0) {
    free(hex);
    return "0";
  } else if (num > 0)
    mask = num;
  else
    mask = ~(-num) + 1;

  int index = 0;
  while (mask) {
    unsigned temp = mask & 0xf;
    hex[index++] = hex_map[temp];
    mask >>= 4;
  }

  // reverse the string

  int i = 0;
  int j = strlen(hex) - 1;

  while (i < j) {
    char temp = hex[i];
    hex[i] = hex[j];
    hex[j] = temp;
    i++;
    j--;
  }

  return hex;
}

int main(void) {
  char *result = toHex(26);

  printf("%s", result);

  return 0;
}
