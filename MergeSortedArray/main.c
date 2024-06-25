#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  // nums1 is the array that will be modified

  int index1 = 0;
  int index2 = 0;
  int aux_index = 0;
  int *aux = (int *)malloc(sizeof(int) * (m + n));

  while (index1 < m && index2 < n) {
    if (nums1[index1] < nums2[index2])
      aux[aux_index++] = nums1[index1++];
    else
      aux[aux_index++] = nums2[index2++];
  }

  while (index1 < m)
    aux[aux_index++] = nums1[index1++];

  while (index2 < n)
    aux[aux_index++] = nums2[index2++];

  for (int i = 0; i < m + n; i++) {
    nums1[i] = aux[i];
  }

  free(aux);
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int nums1[] = {1, 2, 3, 0, 0, 0};
  int nums2[] = {2, 5, 6};

  merge(nums1, 6, 3, nums2, 3, 3);

  print_array(nums1, 6);

  return 0;
}
