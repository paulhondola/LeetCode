int binaryGap(int n) {
  int max_gap = 0;
  int gap = 0;

  while (n) {
    if (n & 1) {
      if (gap > max_gap)
        max_gap = gap;
      gap = 1;
    } else if (gap)
      gap++;

    n >>= 1;
  }

  return max_gap;
}
