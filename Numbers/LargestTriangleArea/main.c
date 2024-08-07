double computeArea(int *a, int *b, int *c) {
  return 0.5 * abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) +
                   c[0] * (a[1] - b[1]));
}

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize) {

  double area = 0;
  for (int i = 0; i < pointsSize; i++) {
    for (int j = i + 1; j < pointsSize; j++) {
      for (int k = j + 1; k < pointsSize; k++) {
        area = fmax(area, computeArea(points[i], points[j], points[k]));
      }
    }
  }

  return area;
}
