int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize) {
  int matrix[m][n];

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      matrix[i][j] = 0;

  for (int i = 0; i < opsSize; i++) {
    for (int j = 0; j < opsColSize[i]; j++) {
      for (int k = 0; k < ops[i][j]; k++) {
        matrix[k][j]++;
      }
    }
  }

  int max_element = matrix[0][0];
  int max_count = 1;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (matrix[i][j] == max_element)
        max_count++;

  return max_count;
}

int main(void) {}
