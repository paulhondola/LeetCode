#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isToeplitzMatrix(int **matrix, int matrixSize, int *matrixColSize) {
  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < matrixColSize[0]; j++) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) {
        return false;
      }
    }
  }
  return true;
}

// Helper function to create a 2D array
int **createMatrix(int rows, int cols) {
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
  return matrix;
}

// Helper function to free a 2D array
void freeMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int rows1 = 3;
  int cols1 = 4;
  int *matrixColSize1 = &cols1;
  int **matrix1 = createMatrix(rows1, cols1);

  int values1[3][4] = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};

  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      matrix1[i][j] = values1[i][j];
    }
  }

  printf("Matrix 1 is Toeplitz: %s\n",
         isToeplitzMatrix(matrix1, rows1, matrixColSize1) ? "True" : "False");
  freeMatrix(matrix1, rows1);

  int rows2 = 2;
  int cols2 = 2;
  int *matrixColSize2 = &cols2;
  int **matrix2 = createMatrix(rows2, cols2);

  int values2[2][2] = {{1, 2}, {2, 2}};

  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < cols2; j++) {
      matrix2[i][j] = values2[i][j];
    }
  }

  printf("Matrix 2 is Toeplitz: %s\n",
         isToeplitzMatrix(matrix2, rows2, matrixColSize2) ? "True" : "False");
  freeMatrix(matrix2, rows2);

  return 0;
}
