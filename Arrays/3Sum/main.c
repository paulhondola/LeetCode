#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

const int CHUNK = 64;

int **realloc_matrix(int **matrix, int *allocated_size, int columns) {
  matrix = realloc(matrix, (*allocated_size + CHUNK) * sizeof(int *));

  for (int i = *allocated_size; i < *allocated_size + CHUNK; i++) {
    matrix[i] = malloc(columns * sizeof(int));
  }

  printf("Allocated %d rows\n", *allocated_size + CHUNK);

  *allocated_size += CHUNK;

  return matrix;
}

// Comparator function for qsort
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compare);

  int used_size = 0;
  int allocated_size = 0;
  int **result = NULL;
  result = realloc_matrix(result, &allocated_size, 3);

  for (int i = 0; i < numsSize - 2; i++) {
    // Skip duplicate elements
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left = i + 1;
    int right = numsSize - 1;

    while (left < right) {
      int current_sum = nums[i] + nums[left] + nums[right];

      if (current_sum == 0) {
        printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);

        if (used_size == allocated_size)
          realloc_matrix(result, &allocated_size, 3);

        result[used_size][0] = nums[i];
        result[used_size][1] = nums[left];
        result[used_size][2] = nums[right];

        used_size++;

        // Skip duplicate elements
        while (left < right && nums[left] == nums[left + 1]) {
          left++;
        }
        while (left < right && nums[right] == nums[right - 1]) {
          right--;
        }

        left++;
        right--;
      } else if (current_sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }

  *returnSize = used_size;

  return result;
}

void print_matrix(int **matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main(void) {
  int v[] = {-1, 0, 1, 2, -1, -4};
  int size = sizeof(v) / sizeof(v[0]);
  int result_size = 0;

  int **result = threeSum(v, size, &result_size, NULL);

  print_matrix(result, result_size, 3);

  return 0;
}
