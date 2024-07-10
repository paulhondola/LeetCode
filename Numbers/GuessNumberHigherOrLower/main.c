int guess(int num) { return num == 6; }

int binarySearch(int start, int end) {
  int mid = (start + end) / 2;
  if (guess(mid) == 0)
    return mid;

  if (guess(mid) == 1)
    return binarySearch(mid + 1, end);
  else
    return binarySearch(start, mid - 1);
}

int guessNumber(int n) { return binarySearch(1, n); }
