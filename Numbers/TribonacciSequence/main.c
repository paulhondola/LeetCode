int tribonacci(int n) {
  // T0 = 0
  // T1 = 1
  // T2 = 1
  // Tn = Tn-1 + Tn-2 + Tn-3

  switch (n) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 1;
  default:
    break;
  }

  int a = 0;
  int b = 1;
  int c = 1;

  for (int i = 3; i < n; i++) {
    int temp = a + b + c;
    a = b;
    b = c;
    c = temp;
  }

  return a + b + c;
}
