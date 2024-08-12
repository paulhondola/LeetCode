int minDeletionSize(char **strs, int strsSize) {
  int min = 0;
  int len = strlen(strs[0]);

  for (int j = 0; j < len; j++) {
    for (int i = 1; i < strsSize; i++) {
      if (strs[i][j] < strs[i - 1][j]) {
        min++;
        break;
      }
    }
  }

  return min;
}
