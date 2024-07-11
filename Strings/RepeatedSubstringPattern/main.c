bool repeatedSubstringPattern(char *s) {

  int len = strlen(s);

  for (int i = 1; i <= len / 2; i++) {
    if (len % i == 0) {
      bool flag = true;
      for (int j = i; j < len; j++) {
        if (s[j] != s[j % i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return true;
      }
    }
  }

  return false;
}
