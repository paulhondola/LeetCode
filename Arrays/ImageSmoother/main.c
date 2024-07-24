#include <stdio.h>
#include <stdlib.h>
int getAverage(int **img, int imgSize, int *imgColSize, int x, int y) {
  int sum = img[x][y], count = 1;
  // N

  if (x - 1 >= 0) {
    sum += img[x - 1][y];
    count++;

    // NW

    if (y - 1 >= 0) {
      sum += img[x - 1][y - 1];
      count++;
    }

    // NE

    if (y + 1 < imgColSize[x - 1]) {
      sum += img[x - 1][y + 1];
      count++;
    }
  }

  // S

  if (x + 1 < imgSize) {
    sum += img[x + 1][y];
    count++;

    // SW

    if (y - 1 >= 0) {
      sum += img[x + 1][y - 1];
      count++;
    }

    // SE

    if (y + 1 < imgColSize[x + 1]) {
      sum += img[x + 1][y + 1];
      count++;
    }
  }

  // W

  if (y - 1 >= 0) {
    sum += img[x][y - 1];
    count++;
  }

  // E

  if (y + 1 < imgColSize[x]) {
    sum += img[x][y + 1];
    count++;
  }

  return sum / count;
}

int **imageGen(int imgSize, int *imgColSize) {
  int **img = (int **)malloc(sizeof(int *) * imgSize);

  for (int i = 0; i < imgSize; i++)
    img[i] = (int *)malloc(sizeof(int) * imgColSize[i]);

  return img;
}

int **imageSmoother(int **img, int imgSize, int *imgColSize, int *returnSize,
                    int **returnColumnSizes) {

  int **smoothedImg = imageGen(imgSize, imgColSize);

  *returnSize = imgSize;

  *returnColumnSizes = (int *)malloc(sizeof(int) * imgSize);

  for (int i = 0; i < imgSize; i++) {
    (*returnColumnSizes)[i] = imgColSize[i];
  }

  for (int i = 0; i < imgSize; i++) {
    for (int j = 0; j < imgColSize[i]; j++) {
      smoothedImg[i][j] = getAverage(img, imgSize, imgColSize, i, j);
    }
  }

  return smoothedImg;
}

int main(void) {
  int imgSize = 3;
  int imgColSize[3] = {3, 3, 3};
  int **img = imageGen(imgSize, imgColSize);

  int returnSize;
  int *returnColumnSizes = NULL;

  int **smoothedImg =
      imageSmoother(img, imgSize, imgColSize, &returnSize, &returnColumnSizes);

  return 0;
}
