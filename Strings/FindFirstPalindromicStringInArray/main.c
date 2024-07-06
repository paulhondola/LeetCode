#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *word) {
  int left = 0;
  int right = strlen(word) - 1;

  while (left < right) {
    if (word[left] != word[right])
      return 0;
    left++;
    right--;
  }

  return 1;
}

const int MAX_STRING_LENGTH = 101;
char *firstPalindrome(char **words, int wordsSize) {
  for (int i = 0; i < wordsSize; i++)
    if (isPalindrome(words[i]))
      return words[i];
  return "";
}

int main(void) {
  char *words[5] = {"abc", "car", "ada", "racecar", "cool"};

  char *result = firstPalindrome(words, 5);

  printf("%s", result);

  return 0;
}
