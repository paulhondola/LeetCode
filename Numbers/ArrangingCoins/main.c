int arrangeCoins(int n) {
  // 1 + 2 + ... + k = k(k+1)/2
  // k > n -> return k - 1
  int k = 1;
  while (n >= k) {
    n -= k;
    k++;
  }

  return k - 1;
}
