#include <stdio.h>

char nextGreatestLetter(char *letters, int lettersSize, char target) {
  int low = 0;
  int high = lettersSize - 1;

  // If target is greater than or equal to the last character, wrap around
  if (target >= letters[high]) {
    return letters[0];
  }

  // Binary search to find the smallest character greater than target
  while (low < high) {
    int mid = low + (high - low) / 2;

    if (letters[mid] > target) {
      high = mid; // Look for a smaller letter in the left half
    } else {
      low = mid + 1; // Look for a greater letter in the right half
    }
  }

  return letters[low];
}

int main() {
  char letters1[] = {'c', 'f', 'j'};
  char target1 = 'a';
  printf("Next greatest letter after '%c': %c\n", target1,
         nextGreatestLetter(letters1, 3, target1)); // Output: c

  char letters2[] = {'c', 'f', 'j'};
  char target2 = 'c';
  printf("Next greatest letter after '%c': %c\n", target2,
         nextGreatestLetter(letters2, 3, target2)); // Output: f

  char letters3[] = {'c', 'f', 'j'};
  char target3 = 'k';
  printf("Next greatest letter after '%c': %c\n", target3,
         nextGreatestLetter(letters3, 3, target3)); // Output: c

  return 0;
}
