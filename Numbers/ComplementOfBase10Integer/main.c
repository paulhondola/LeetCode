int bitwiseComplement(int n) {
  // Special case for 0
  if (n == 0)
    return 1;

  // Calculate the highest power of 2 greater than n
  int power = 1;
  while (power <= n)
    power <<= 1;

  // Subtract 1 to get a mask with all bits set to 1 up to the highest bit of n
  int mask = power - 1;

  // XOR n with mask to get the complement
  return n ^ mask;
}
