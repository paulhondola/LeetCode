bool isDividingNumber(int num) {
  int temp = num;

  while (temp) {
    int digit = temp % 10;
    if (!digit)
      return false;

    if (num % digit)
      return false;

    temp /= 10;
  }

  return true;
}

int *selfDividingNumbers(int left, int right, int *returnSize) {

  int len = right - left + 1;

  int *result = (int *)malloc(len * sizeof(int));

  int index = 0;

  for (int i = left; i <= right; i++) {
    if (isDividingNumber(i)) {
      result[index++] = i;
    }
  }

  *returnSize = index;

  return result;
}
