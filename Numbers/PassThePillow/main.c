int passThePillow(int n, int time) {
  const int max = 2 * n - 2;
  const int remaining = time % max;

  if (remaining < n)
    return remaining + 1;
  else
    return max - remaining + 1;
}
