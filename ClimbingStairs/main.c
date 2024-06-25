// sum = 2
// opt = 1 / 2
// backtrack

#include <stdio.h>

int successor(int stack[], int level, int *level_sum, int sum) {
  if (stack[level] >= 2)
    return 0;

  stack[level]++;
  (*level_sum)++;

  if (sum < *level_sum)
    return 0;

  return 1;
}

int valid(int stack[], int level, int level_sum) {

  int my_sum = 0;

  for (int i = 1; i <= level; i++) {
    my_sum += stack[i];
    if (my_sum > level_sum)
      return 0;
  }

  return 1;
}

int solution(int level_sum, int sum) { return level_sum == sum; }

void print_solution(int stack[], int level) {
  for (int i = 1; i <= level; i++)
    printf("%d ", stack[i]);

  printf("\n");
}

int back(int sum) {
  int permutations = 0;

  if (sum == 0)
    return 0;

  if (sum == 1)
    return 1;

  const int init_val = 0;
  const int max_size = 45;
  int stack[max_size];
  stack[0] = init_val;
  stack[1] = init_val;

  int level_sum = 0;

  int level = 1;

  while (level > init_val) {
    if (successor(stack, level, &level_sum, sum)) {
      if (valid(stack, level, sum)) {
        if (solution(level_sum, sum)) {
          permutations++;
          // print_solution(stack, level);
        } else {
          level++;
          stack[level] = init_val;
        }
      } else {
        ;
      }
    } else {
      level_sum -= stack[level];
      level--;
    }
  }

  return permutations;
}

int main(void) {
  printf("The number of permutations is %d\n", back(35));

  return 0;
}
