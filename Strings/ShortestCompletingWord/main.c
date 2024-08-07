char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize) {
  int hashmap[26] = {0};

  // Count the frequency of each character in the license plate

  for (int i = 0; licensePlate[i] != '\0'; i++) {
    if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
      hashmap[licensePlate[i] - 'a']++;
    } else if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
      hashmap[licensePlate[i] - 'A']++;
    }
  }

  int hashmatrix[wordsSize][26];

  for (int i = 0; i < wordsSize; i++) {
    for (int j = 0; j < 26; j++) {
      hashmatrix[i][j] = 0;
    }
  }

  // Count the frequency of each character in each word

  for (int i = 0; i < wordsSize; i++)
    for (int j = 0; words[i][j] != '\0'; j++)
      hashmatrix[i][words[i][j] - 'a']++;

  int min_len = 16;
  char *result = words[0];

  for (int i = 0; i < wordsSize; i++) {
    int flag = 1;
    for (int j = 0; j < 26; j++) {
      if (hashmap[j] > hashmatrix[i][j]) {
        flag = 0;
        break;
      }
    }

    if (flag && (strlen(words[i]) < min_len)) {
      min_len = strlen(words[i]);
      result = words[i];
    }
  }

  return result;
}
