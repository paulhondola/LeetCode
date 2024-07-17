int findLUSlength(char *a, char *b) {
  int len_a = strlen(a);
  int len_b = strlen(b);

  // check if strings are equal

  bool flag = true;

  if (len_a == len_b) {

    for (int i = 0; i < len_a; i++)
      if (a[i] != b[i])
        flag = false;

    if (flag)
      return -1;
    else
      return len_a;
  }

  return len_a > len_b ? len_a : len_b;
}

/*
int findLUSlength(char* a, char* b) {
    return strcmp(a, b) ? fmax(strlen(a), strlen(b)) : -1;
}
*/
