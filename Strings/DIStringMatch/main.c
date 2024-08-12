int *diStringMatch(char *s, int *returnSize) {
  int len = strlen(s);
  *returnSize = len + 1;
  int *res = (int *)malloc(sizeof(int) * (*returnSize));
  int low = 0, high = len;

  for (int i = 0; i < len; i++) {
    if (s[i] == 'I') {
      res[i] = low++;
    } else {
      res[i] = high--;
    }
  }

  res[len] = low;
  return res;
}
