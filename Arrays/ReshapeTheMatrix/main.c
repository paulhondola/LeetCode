int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c,
                    int *returnSize, int **returnColumnSizes) {

  // invalid case
  if (matSize * (*matColSize) != r * c) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
  }

  // matrix allocation
  int **result = (int **)malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++)
    result[i] = (int *)malloc(c * sizeof(int));

  // matrix reshape
  int i_matrix = 0, j_matrix = 0, i_reshape = 0, j_reshape = 0;

  for (i_matrix = 0; i_matrix < matSize; i_matrix++) {
    for (j_matrix = 0; j_matrix < *matColSize; j_matrix++) {
      result[i_reshape][j_reshape] = mat[i_matrix][j_matrix];
      j_reshape++;
      if (j_reshape == c) {
        j_reshape = 0;
        i_reshape++;
      }
    }
  }

  *returnSize = r;
  *returnColumnSizes = (int *)malloc(r * sizeof(int));
  for (int i = 0; i < r; i++)
    (*returnColumnSizes)[i] = c;
  return result;
}
