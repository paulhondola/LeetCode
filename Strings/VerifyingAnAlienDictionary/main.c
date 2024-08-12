bool isAlienSorted(char **words, int wordsSize, char *order) {
  int orderMap[26];
  for (int i = 0; i < 26; i++)
    orderMap[order[i] - 'a'] = i;

  for (int i = 0; i < wordsSize - 1; i++) {
    char *word1 = words[i];
    char *word2 = words[i + 1];
    while (*word1 && *word2) {
      if (orderMap[*word1 - 'a'] < orderMap[*word2 - 'a'])
        break;
      if (orderMap[*word1 - 'a'] > orderMap[*word2 - 'a'])
        return false;
      word1++;
      word2++;
    }
    if (!*word1 && *word2)
      return true;
    if (*word1 && !*word2)
      return false;
  }

  return true;
}
