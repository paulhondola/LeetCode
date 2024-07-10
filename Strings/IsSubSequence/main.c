bool isSubsequence(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);

  int index_s = 0;
  int index_t = 0;

  while (index_s < len_s && index_t < len_t) {
    if (s[index_s] == t[index_t]) {
      index_s++;
    }
    index_t++;
  }

  return index_s == len_s;
}
