bool backspaceCompare(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);

  char stack_s[len_s + 1];
  char stack_t[len_t + 1];

  int top_s = 0;
  int top_t = 0;

  for (int i = 0; i <= len_s; i++) {
    if (s[i] == '#') {
      if (top_s > 0)
        top_s--;
    } else
      stack_s[top_s++] = s[i];
  }

  for (int i = 0; i <= len_t; i++) {
    if (t[i] == '#') {
      if (top_t > 0)
        top_t--;
    } else
      stack_t[top_t++] = t[i];
  }

  return strcmp(stack_s, stack_t) == 0;
}
