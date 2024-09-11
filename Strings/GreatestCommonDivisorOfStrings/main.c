#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the GCD of two integers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int divisionCondition(int a, int b) {
  if (a > b && a % b == 0)
    return 1;
  if (b > a && b % a == 0)
    return 1;
  return 0;
}

// Function to check if a string `t` can be formed by repeating string `s`
int canFormByRepeating(char *s, char *t) {
  const int len_s = strlen(s);
  const int len_t = strlen(t);

  // Check if `t` can be formed by repeating `s`
  for (int i = 0; i < len_t; i++) {
    if (t[i] != s[i % len_s]) {
      return 0;
    }
  }

  return 1;
}

int checkConcatCondition(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);
  char forward[len_s + len_t + 1];
  char backward[len_s + len_t + 1];

  strcpy(forward, s);
  strcat(forward, t);

  strcpy(backward, t);
  strcat(backward, s);

  return strcmp(forward, backward) == 0;
}

// Function to find the GCD string
char *gcdOfStrings(char *str1, char *str2) {
  // Find the GCD of the lengths of the two strings
  const int len1 = strlen(str1);
  const int len2 = strlen(str2);
  int gcd_len = gcd(len1, len2);
  char *gcd_str = malloc((gcd_len + 1) * sizeof(char));

  // Check if str1 + str2 equals str2 + str1
  if (!checkConcatCondition(str1, str2)) {
    perror("CONCAT CONDITION NOT MET");
    gcd_str[0] = 0;
    return gcd_str;
  }

  // Extract the GCD string
  strncpy(gcd_str, str1, gcd_len);
  gcd_str[gcd_len] = 0;

  if (!canFormByRepeating(str1, gcd_str) ||
      !canFormByRepeating(str2, gcd_str)) {
    perror("REPEATING CONDITION NOT MET");
    gcd_str[0] = 0;
    return gcd_str;
  }

  return gcd_str;
}

// Main function to test the gcdOfStrings function
int main() {
  char str1[] = "ABCABC";
  char str2[] = "ABC";

  char *result = gcdOfStrings(str1, str2);
  if (strlen(result) > 0) {
    printf("The GCD of strings is: %s\n", result);
  } else {
    printf("There is no common divisor string.\n");
  }

  free(result);
  return 0;
}
