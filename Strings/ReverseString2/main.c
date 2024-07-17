char *reverseStr(char *s, int k) {
  // select groups of 2*k characters and reverse the first k characters

  int len = strlen(s);
  for (int i = 0; i < len; i += 2 * k) {
    int start = i;
    int end = i + k - 1;
    if (end >= len)
      end = len - 1;

    while (start < end) {
      char temp = s[start];
      s[start] = s[end];
      s[end] = temp;
      start++;
      end--;
    }
  }

  return s;
}
