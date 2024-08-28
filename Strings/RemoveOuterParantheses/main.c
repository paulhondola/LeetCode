#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeOuterParentheses(char *S) {
  int open_count = 0;
  int len = strlen(S);
  char *result =
      (char *)malloc(len + 1); // Allocate memory for the result string
  int j = 0;                   // Index for the result string

  for (int i = 0; i < len; i++) {
    if (S[i] == '(') {
      if (open_count > 0) {
        result[j++] = S[i]; // Add '(' to result if it's not the outermost
      }
      open_count++;
    } else if (S[i] == ')') {
      open_count--;
      if (open_count > 0) {
        result[j++] = S[i]; // Add ')' to result if it's not the outermost
      }
    }
  }

  result[j] = '\0'; // Null-terminate the result string
  return result;
}

int main() {
  char S[] = "(()())(())"; // Example input
  char *result = removeOuterParentheses(S);
  printf("Result: %s\n", result); // Output should be "()()()"

  free(result); // Free the allocated memory
  return 0;
}
