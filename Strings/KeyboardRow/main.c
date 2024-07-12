#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **findWords(char **words, int wordsSize, int *returnSize) {
  const char *rows[26] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

  char **result = (char **)malloc(wordsSize * sizeof(char *));

  int count = 0;

  for (int i = 0; i < wordsSize; i++) {
    int len = strlen(words[i]);
    int row_index = 0;

    if (strchr(rows[0], tolower(words[i][0])) != NULL) {
      row_index = 0;
    } else if (strchr(rows[1], tolower(words[i][0])) != NULL) {
      row_index = 1;
    } else {
      row_index = 2;
    }

    bool valid = true;
    for (int j = 1; j < len; j++) {
      if (strchr(rows[row_index], tolower(words[i][j])) == NULL) {
        valid = false;
        break;
      }
    }

    if (valid) {
      result[count++] = words[i];
    }
  }

  *returnSize = count;
  return result;
}
