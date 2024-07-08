#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char *s, char *t) {

  int len_s = strlen(s);
  int len_t = strlen(t);

  if (len_s != len_t)
    return false;

  char s2t[128] = {0};
  char t2s[128] = {0};

  for (int i = 0; i < len_s; i++) {
    if (s2t[s[i]] != t2s[t[i]])
      return false;

    s2t[s[i]] = i;
    t2s[t[i]] = i;
  }

  return true;
}
