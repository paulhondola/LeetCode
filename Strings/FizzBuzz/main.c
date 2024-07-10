#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *convertIntToString(int n, int maxsize) {
  char *str = (char *)malloc(maxsize * sizeof(char));
  sprintf(str, "%d", n);
  return str;
}

char **fizzBuzz(int n, int *returnSize) {
  char **matrix = (char **)malloc(n * sizeof(char *));

  // fizz -> %3
  // buzz -> %5
  // fizzbuzz -> %15

  const int fizzbuzz = 9;
  const int fizz = 5;
  const int buzz = 5;
  const int none = 6; // up to 10000

  for (int i = 0; i < n; i++) {
    if ((i + 1) % 15 == 0) {
      matrix[i] = (char *)malloc(fizzbuzz * sizeof(char));
      strcpy(matrix[i], "FizzBuzz\0");
    } else if ((i + 1) % 3 == 0) {
      matrix[i] = (char *)malloc(fizz * sizeof(char));
      strcpy(matrix[i], "Fizz");

    } else if ((i + 1) % 5 == 0) {
      matrix[i] = (char *)malloc(buzz * sizeof(char));
      strcpy(matrix[i], "Buzz\0");
    } else {
      matrix[i] = (char *)malloc(none * sizeof(char));
      strcpy(matrix[i], convertIntToString(i + 1, none));
    }
  }

  *returnSize = n;

  return matrix;
}

int main(void) {
  int returnSize = 0;
  char **fizzbuzz = fizzBuzz(5, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%s ", fizzbuzz[i]);
  }

  return 0;
}
