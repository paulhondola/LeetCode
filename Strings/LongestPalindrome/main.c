int longestPalindrome(char *s) {
  // sum of all even character count and the largest odd char count
  int count[128] = {0};
  int max_odd = 0;
  int sum_even = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    count[s[i]]++;
  }

  for (int i = 0; i < 128; i++) {
    if (count[i] % 2)
      max_odd = count[i] > max_odd ? count[i] : max_odd;

    sum_even += count[i] % 2 ? count[i] - 1 : count[i];
  }

  if (max_odd)
    max_odd = 1;

  return sum_even + max_odd;
}
