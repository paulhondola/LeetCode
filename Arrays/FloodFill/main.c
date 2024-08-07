/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

void fill(int **image, int imageSize, int *imageColSize, int x, int y,
          int color, int color_filled) {
  if (x < 0 || x >= imageSize || y < 0 || y >= imageColSize[x] ||
      image[x][y] == color || image[x][y] != color_filled)
    return;

  image[x][y] = color;

  fill(image, imageSize, imageColSize, x + 1, y, color, color_filled);
  fill(image, imageSize, imageColSize, x - 1, y, color, color_filled);
  fill(image, imageSize, imageColSize, x, y + 1, color, color_filled);
  fill(image, imageSize, imageColSize, x, y - 1, color, color_filled);
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc,
                int color, int *returnSize, int **returnColumnSizes) {

  *returnSize = imageSize;

  *returnColumnSizes = (int *)malloc(imageSize * sizeof(int));
  for (int i = 0; i < imageSize; i++)
    (*returnColumnSizes)[i] = imageColSize[i];

  int color_filled = image[sr][sc];

  fill(image, imageSize, imageColSize, sr, sc, color, color_filled);

  return image;
}
