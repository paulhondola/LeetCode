int numJewelsInStones(char *jewels, char *stones) {
  int len_jewels = strlen(jewels);
  int len_stones = strlen(stones);
  int hash[128] = {0};

  for (int i = 0; i < len_jewels; i++) {
    hash[jewels[i]] = 1;
  }

  int count = 0;
  for (int i = 0; i < len_stones; i++) {
    if (hash[stones[i]]) {
      count++;
    }
  }
  return count;
}
