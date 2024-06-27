#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **generate_matrix(int rows, int collumns) {
  char **matrix = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (char *)malloc(collumns * sizeof(char));

    for (int j = 0; j < collumns; j++)
      matrix[i][j] = ' ';
  }
  return matrix;
}

void print_matrix(char **matrix, int rows, int collumns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < collumns; j++)
      printf("%c ", matrix[i][j]);
    printf("\n");
  }
}

void go_down(char *s, int len, int *filled, char **matrix, int numRows,
             int *collumn) {
  // Down
  for (int i = 0; i < numRows; i++) {
    if (*filled == len)
      break;
    matrix[i][*collumn] = s[(*filled)++];
  }

  (*collumn)++;
}

void go_up_diagonal(char *s, int len, int *filled, char **matrix, int numRows,
                    int *collumn) {
  // Up diagonal
  for (int i = numRows - 2; i > 0; i--) {

    if (*filled == len)
      break;

    matrix[i][*collumn] = s[(*filled)++];

    (*collumn)++;
  }
}

void free_matrix(char **matrix, int rows) {
  for (int i = 0; i < rows; i++)
    free(matrix[i]);
  free(matrix);
}

void create_string(char *string, char **matrix, int rows, int collumns) {
  int index = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < collumns; j++)
      if (matrix[i][j] != ' ')
        string[index++] = matrix[i][j];
  string[index] = '\0';
}

char *convert(char *s, int numRows) {

  char *new = (char *)malloc(strlen(s) + 1);

  if (numRows == 1) {
    strcpy(new, s);
    return new;
  }

  // char *result = (char *)malloc((strlen(s) + 1) * sizeof(char));
  int len = strlen(s);
  char **matrix = generate_matrix(numRows, len);

  int collumn = 0, filled = 0;

  while (1) {
    if (filled == len)
      break;
    go_down(s, len, &filled, matrix, numRows, &collumn);
    go_up_diagonal(s, len, &filled, matrix, numRows, &collumn);
  }

  print_matrix(matrix, numRows, len);

  create_string(new, matrix, numRows, len);

  free_matrix(matrix, numRows);

  return new;
}

int main(void) {
  char *s = "PAYPALISHIRING";
  // output -> "PAHNAPLSIIGYIR"

  printf("%s", convert(s, 4));

  return 0;
}
