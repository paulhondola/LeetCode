#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *distributeCandies(int candies, int num_people, int *returnSize) {
  *returnSize = num_people;
  int *result = calloc(num_people, sizeof(int));

  int candies_to_give = 0;

  int people_cycle = -1;

  while (1) {
    candies_to_give++;
    people_cycle++;

    people_cycle %= num_people;

    if (candies_to_give > candies) {
      candies_to_give = candies;
      result[people_cycle] += candies_to_give;
      break;
    }

    candies -= candies_to_give;

    result[people_cycle] += candies_to_give;
  }

  return result;
}

int main() {

  int candies = 7;
  int num_people = 4;
  int returnSize = 0;

  int *result = distributeCandies(candies, num_people, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }

  free(result);

  return 0;
}
