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

int **generate(int numRows) {
  int **matrix = alloc_matrix(numRows);

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

int* getRow(int rowIndex, int* returnSize) {
    int **matrix = generate(rowIndex + 1);
    int *row = matrix[rowIndex];
    *returnSize = rowIndex + 1;
    return row;
}
