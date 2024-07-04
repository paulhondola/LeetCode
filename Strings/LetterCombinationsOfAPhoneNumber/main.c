#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the total number of combinations
void computeSize(char *digits, int *rows) {
  int len = strlen(digits);
  int size = 1;

  for (int i = 0; i < len; i++) {
    int digit = digits[i] - '0';
    if (digit == 7 || digit == 9) {
      size *= 4; // Digits 7 and 9 have 4 letters each
    } else {
      size *= 3; // Other digits have 3 letters each
    }
  }

  *rows = size;
}

// Function to allocate memory for the matrix of combinations
char **allocMatrix(int rows, int columns) {
  char **matrix = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    matrix[i] =
        (char *)malloc((columns + 1) * sizeof(char)); // +1 for null terminator
  }
  return matrix;
}

// Function to find the next valid combination in the stack
int successor(char *digits, int stack[], int level) {
  int size = (digits[level] == '7' || digits[level] == '9') ? 4 : 3;

  if (stack[level] >= size - 1)
    return 0;

  stack[level]++;
  return 1;
}

// Function to determine if the current stack level represents a complete
// solution
int solution(char *digits, int stack[], int level, int size) {
  return level == size - 1;
}

// Function to load the solution into the matrix
void loadSolution(char **matrix, const char *digits, const char letters[][4],
                  int stack[], int permutations, int size) {
  for (int i = 0; i < size; i++) {
    matrix[permutations][i] = letters[digits[i] - '0'][stack[i]];
  }
  matrix[permutations][size] = '\0'; // Null-terminate the string
}

// Backtracking function to generate all combinations
void back(char **matrix, char *digits) {
  const int size = strlen(digits);
  const char letters[][4] = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};

  int permutations = 0;
  int stack[size];
  int level = 0;
  stack[0] = -1;

  while (level > -1) {
    if (successor(digits, stack, level)) {
      if (solution(digits, stack, level, size)) {
        loadSolution(matrix, digits, letters, stack, permutations, size);
        permutations++;
      } else {
        level++;
        stack[level] = -1;
      }
    } else {
      level--;
    }
  }
}

// Main function to generate the letter combinations
char **letterCombinations(char *digits, int *returnSize) {
  computeSize(digits, returnSize);
  char **matrix = allocMatrix(*returnSize, strlen(digits));

  if (*digits) { // Check if digits is not empty
    back(matrix, digits);
  } else {
    *returnSize = 0; // No combinations if the input is empty
  }

  return matrix;
}

// Helper function to print the matrix of combinations
void printMatrix(char **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    printf("%s\n", matrix[i]);
  }
}

// Main driver function
int main(void) {
  char *digits = "272";
  int len = strlen(digits);
  int returnSize = 0;

  char **result = letterCombinations(digits, &returnSize);

  printf("%d %d\n", returnSize, len);
  printMatrix(result, returnSize);

  // Free allocated memory
  for (int i = 0; i < returnSize; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}
