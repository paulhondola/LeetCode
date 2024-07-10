int firstUniqChar(char *s) {
  int chars[26] = {0};

  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    chars[s[i] - 'a']++;
  }

  for (int i = 0; i < len; i++) {
    if (chars[s[i] - 'a'] == 1) {
      return i;
    }

    return -1;
  }
