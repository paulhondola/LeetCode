char findTheDifference(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);

  int chars_s[26] = {0};

  for (int i = 0; i < len_s; i++) {
    chars_s[s[i] - 'a']++;
  }

  for (int i = 0; i < len_t; i++) {
    if (chars_s[t[i] - 'a'] == 0) {
      return t[i];
    }

    chars_s[t[i] - 'a']--;
  }

  return 0;
}
