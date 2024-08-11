#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool buddyStrings(char *s, char *goal) {
  int s_map[26] = {0};
  int goal_map[26] = {0};

  int s_len = strlen(s);
  int goal_len = strlen(goal);

  if (s_len != goal_len)
    return false;

  for (int i = 0; i < s_len; i++) {
    s_map[s[i] - 'a']++;
    goal_map[goal[i] - 'a']++;
  }

  // check if there are the same characters in s and goal

  for (int i = 0; i < s_len; i++)
    if (s_map[s[i] - 'a'] != goal_map[s[i] - 'a']) {

      return false;
    }

  int diff = 0;

  for (int i = 0; i < s_len; i++)
    if (s[i] != goal[i])
      diff++;

  // check if there are double characters in s and goal

  for (int i = 0; i < 26; i++) {
    printf("%d ", s_map[i]);
  }

  printf("\n");

  for (int i = 0; i < 26; i++) {
    printf("%d ", goal_map[i]);
  }

  printf("\n");

  if (diff == 0) {
    for (int i = 0; i < 26; i++)
      if (s_map[i] > 1) {

        return true;
      }

    return false;
  }

  return diff == 2;
}

int main(void) {
  char s[] = "aa";
  char goal[] = "aa";

  printf("%d", buddyStrings(s, goal));
}
