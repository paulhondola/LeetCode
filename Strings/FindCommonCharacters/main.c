#include <stdio.h>
#include <stdlib.h>

void initHashMap(int hash[][26], const int size) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < 26; j++)
      hash[i][j] = 0;
}

void fillHashMap(int hash[][26], char **words, const int wordsSize) {
  for (int i = 0; i < wordsSize; i++)
    for (int j = 0; words[i][j] != '\0'; j++)
      hash[i][words[i][j] - 'a']++;
}

void fillCharMap(int map[], int hashmap[][26], int size) {
  const int MAX_VAL = 100;
  for (int i = 0; i < 26; i++) {
    int min = MAX_VAL;
    for (int j = 0; j < size; j++)
      if (hashmap[j][i] < min)
        min = hashmap[j][i];

    map[i] = min;
  }
}

int getNonZeroMapSize(int map[], int size) {
  int count = 0;
  for (int i = 0; i < size; i++)
    if (map[i] != 0)
      count += map[i];
  return count;
}

char **initResult(int charmap[], int size) {
  char **result = (char **)malloc(sizeof(char *) * size);

  int index = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < charmap[i]; j++) {
      result[index] = (char *)malloc(sizeof(char) * 2);
      result[index][0] = i + 'a';
      result[index][1] = '\0';
      index++;
    }
  }

  return result;
}

void printCharMap(int map[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", map[i]);
  printf("\n");
}

char **commonChars(char **words, const int wordsSize, int *returnSize) {
  int hashmap[wordsSize][26];
  int charmap[26];
  initHashMap(hashmap, wordsSize);
  fillHashMap(hashmap, words, wordsSize);
  fillCharMap(charmap, hashmap, wordsSize);
  printCharMap(charmap, 26);
  *returnSize = getNonZeroMapSize(charmap, 26);
  printf("\nRETURN SIZE: %d\n", *returnSize);
  char **result = initResult(charmap, *returnSize);
  return result;
}

int main(void) {
  char **words;
  int wordsSize = 3;
  words = (char **)malloc(sizeof(char *) * wordsSize);
  words[0] = "bella";
  words[1] = "label";
  words[2] = "roller";
  int returnSize = 0;

  char **result = commonChars(words, wordsSize, &returnSize);

  for (int i = 0; i < returnSize; i++)
    printf("%s ", result[i]);

  return 0;
}
