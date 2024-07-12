int *constructRectangle(int area, int *returnSize) {
  int *sizes = (int *)malloc(sizeof(int) * 2);

  int i = sqrt(area);
  int j = i;

  while (i * j != area) {
    i++;
    j = area / i;
  }

  sizes[0] = i;
  sizes[1] = j;

  *returnSize = 2;
  return sizes;
}
