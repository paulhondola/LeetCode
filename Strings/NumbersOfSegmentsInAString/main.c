

int countSegments(char *s) {
  const char *delim = "!@#$\%^&*()_+-=',.: ";
  char *token = strtok(s, delim);

  int count = 0;
  while (token) {
    count++;
    token = strtok(NULL, delim);
  }
  return count;
}
