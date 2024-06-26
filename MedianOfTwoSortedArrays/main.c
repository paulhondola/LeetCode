#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  double median = 0;

  int size = nums1Size + nums2Size;

  int *merged = (int *)malloc(size * sizeof(int));

  int index1 = 0, index2 = 0;

  while (index1 < nums1Size && index2 < nums2Size) {
    if (nums1[index1] < nums2[index2]) {
      merged[index1 + index2] = nums1[index1];
      index1++;
    } else {
      merged[index1 + index2] = nums2[index2];
      index2++;
    }
  }

    while (index1 < nums1Size) {
        merged[index1 + index2] = nums1[index1];
        index1++;
    }

    while (index2 < nums2Size) {
        merged[index1 + index2] = nums2[index2];
        index2++;
    }

    if (size % 2 == 0) {
        median = (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        median = merged[size / 2];
    }

  free(merged);

  return median;
}

int main(void) {
  int a[] = {1, 2};
  int b[] = {3, 4};

  printf("%lf", findMedianSortedArrays(a, 2, b, 2));

  return 0;
}
