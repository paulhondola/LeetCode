#include <stdbool.h>
#include <string.h>
bool isAnagram(char *s, char *t) {

  int ascii_s[128] = {0};
  int ascii_t[128] = {0};

  int len_s = strlen(s);
  int len_t = strlen(t);

  if (len_s != len_t)
    return false;

  for (int i = 0; i < len_s; i++) {
    ascii_s[s[i]]++;
    ascii_t[t[i]]++;
  }

  for (int i = 0; i < 128; i++) {
    if (ascii_s[i] != ascii_t[i])
      return false;
  }

  return true;
}
