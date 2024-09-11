#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillCharMap(char *map, char *chars) {
  int len = strlen(chars);
  for (int i = 0; i < len; i++)
    map[chars[i] - 'a']++;
}

int checkWordFormation(char *word, char *map) {
  char temp_map[26] = {0};
  fillCharMap(temp_map, word);

  for (int i = 0; i < 26; i++)
    if (temp_map[i] > map[i])
      return 0;

  return 1;
}

int countCharacters(char **words, int wordsSize, char *chars) {

  char char_map[26] = {0};
  fillCharMap(char_map, chars);

  int count = 0;

  for (int i = 0; i < wordsSize; i++)
    count += checkWordFormation(words[i], char_map) ? strlen(words[i]) : 0;

  return count;
}

int main() {

  char *words[] = {"cat", "bt", "hat", "tree"};
  char chars[] = "atach";

  int wordsSize = sizeof(words) / sizeof(words[0]);

  printf("%d\n", countCharacters(words, wordsSize, chars));

  return 0;
}
