int *fairCandySwap(int *aliceSizes, int aliceSizesSize, int *bobSizes,
                   int bobSizesSize, int *returnSize) {
  *returnSize = 2;
  int *result = (int *)malloc(sizeof(int) * 2);

  // SumA - a + b = SumB - b + a => a = b + (SumA - SumB) / 2

  int sumA = 0;
  for (int i = 0; i < aliceSizesSize; i++) {
    sumA += aliceSizes[i];
  }

  int sumB = 0;
  for (int i = 0; i < bobSizesSize; i++) {
    sumB += bobSizes[i];
  }

  int diff = (sumA - sumB) / 2;

  for (int i = 0; i < aliceSizesSize; i++) {
    for (int j = 0; j < bobSizesSize; j++) {
      if (aliceSizes[i] == bobSizes[j] + diff) {
        result[0] = aliceSizes[i];
        result[1] = bobSizes[j];
        return result;
      }
    }
  }

  return NULL;
}
