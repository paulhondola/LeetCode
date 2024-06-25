#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

int **alloc_matrix(int numRows) {
  int **matrix = (int **)malloc(numRows * sizeof(int *));
  for (int i = 1; i <= numRows; i++) {
    matrix[i - 1] = (int *)malloc(i * sizeof(int));
  }
  return matrix;
}

int *alloc_column_sizes(int numRows) {
  int *columnSizes = (int *)malloc(numRows * sizeof(int));
  for (int i = 1; i <= numRows; i++)
    columnSizes[i - 1] = i;
  return columnSizes;
}

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  int **matrix = alloc_matrix(numRows);

  *returnSize = numRows;
  *returnColumnSizes = alloc_column_sizes(numRows);

  matrix[0][0] = 1;

  for (int i = 1; i < numRows; i++) {
    matrix[i][0] = 1;
    matrix[i][i] = 1;
    for (int j = 1; j < i; j++) {
      matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
    }
  }

  return matrix;
}
