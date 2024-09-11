#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillMap(int *map, const char *text) {
  const int len = strlen(text);
  for (int i = 0; i < len; i++)
    map[text[i] - 'a']++;
}

int maxNumberOfBalloons(char *text) {
  int main_map[26] = {0};
  int text_map[26] = {0};
  fillMap(main_map, "balloon");
  fillMap(text_map, text);

  int min = INT_MAX;
  for (int i = 0; i < 26; i++) {
    if (main_map[i] == 0)
      continue;
    if (text_map[i] == 0)
      return 0;
    if (i == 'l' - 'a' || i == 'o' - 'a') {
      min = min < text_map[i] / 2 ? min : text_map[i] / 2;
    } else {
      min = min < text_map[i] ? min : text_map[i];
    }
  }

  return min;
}

int main() {

  char *text = "loonbalxballpoon";

  printf("%d\n", maxNumberOfBalloons(text));

  return 0;
}
