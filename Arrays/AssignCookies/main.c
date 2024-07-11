int comparator(const void *p, const void *q) { return (*(int *)p - *(int *)q); }

int findContentChildren(int *g, int gSize, int *s, int sSize) {
  // sort g and s

  qsort(g, gSize, sizeof(int), comparator);
  qsort(s, sSize, sizeof(int), comparator);

  int s_index = 0, g_index = 0;

  while (s_index < sSize && g_index < gSize) {
    if (s[s_index] >= g[g_index]) {
      g_index++;
    }
    s_index++;
  }
  return g_index;
}
