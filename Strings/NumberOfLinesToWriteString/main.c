int *numberOfLines(int *widths, int widthsSize, char *s, int *returnSize) {
  int lines = 1;
  int width = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    int w = widths[s[i] - 'a'];
    if (width + w > 100) {
      lines++;
      width = w;
    } else {
      width += w;
    }
  }

  *returnSize = 2;
  int *result = (int *)malloc(sizeof(int) * 2);
  result[0] = lines;
  result[1] = width;
  return result;
}
