bool detectCapitalUse(char *word) {
  const char start = 'A';
  const char end = 'Z';
  int len = strlen(word);

  if (len < 2)
    return true;

  if (word[0] >= start && word[0] <= end) {
    if (word[1] >= start && word[1] <= end) {
      // All letters in this word are capitals, like "USA".
      for (int i = 2; i < len; i++) {
        if (word[i] < start || word[i] > end)
          return false;
      }
    } else {
      // Only the first letter in this word is capital, like "Google".

      for (int i = 2; i < len; i++) {
        if (word[i] >= start && word[i] <= end)
          return false;
      }
    }

  } else {
    // All letters in this word are not capitals, like "leetcode".

    for (int i = 1; i < len; i++) {
      if (word[i] >= start && word[i] <= end)
        return false;
    }
  }

  return true;
}
