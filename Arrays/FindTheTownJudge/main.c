#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int **trust, int trustSize, int *trustColSize) {
  int *trusts = (int *)calloc(n + 1, sizeof(int));

  for (int i = 0; i < trustSize; i++) {
    trusts[trust[i][0]]--;
    trusts[trust[i][1]]++;
  }

  for (int i = 1; i <= n; i++)
    if (trusts[i] == n - 1)
      return i;

  return -1;
}
