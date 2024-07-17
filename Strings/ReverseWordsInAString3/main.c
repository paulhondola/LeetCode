#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *s) {
  int left = 0, right = strlen(s) - 1;

  while (left < right) {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    left++;
    right--;
  }
}

char *reverseWords(char *s) {
  int len = strlen(s);

  char *aux = (char *)malloc(len + 1);
  char *reversed = (char *)malloc(len + 2);

  reversed[0] = '\0';
  strcpy(aux, s);

  const char *space = " \0";

  char *token = strtok(aux, space);

  int index = 0;

  while (token) {
    reverseString(token);
    strcat(reversed, token);
    strcat(reversed, space);
    token = strtok(NULL, space);
  }

  reversed[len] = '\0';

  free(aux);

  return reversed;
}

int main(void) {
  char *s = "Let's take LeetCode contest";
  char *reversed = reverseWords(s);

  printf("%s\n", reversed);

  free(reversed);

  return 0;
}
