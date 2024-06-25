#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adder(char a, char b, char *sum, char *carry) {
  int a_int = a - '0';
  int b_int = b - '0';
  int carry_int = (*carry) - '0';
  int sum_int = 0;

  sum_int = a_int ^ b_int ^ carry_int;
  carry_int = (a_int & b_int) | (a_int & carry_int) | (b_int & carry_int);

  *sum = sum_int + '0';
  *carry = carry_int + '0';
}

char *addBinary(char *a, char *b) {

  int len_a = strlen(a);
  int len_b = strlen(b);
  int max_len = len_a > len_b ? len_a : len_b;
  int min_len = len_a < len_b ? len_a : len_b;

  char *result = (char *)malloc(sizeof(char) * (max_len + 2));

  if (result == NULL)
    return NULL;

  result[max_len + 1] = '\0';
  result[0] = '0';

  char carry = '0';
  int index_a = len_a - 1;
  int index_b = len_b - 1;
  int index_res = max_len;

  for (int i = 0; i < min_len; i++) {
    adder(a[index_a], b[index_b], &result[index_res], &carry);

    printf("a: %c b: %c res: %c carry: %c\n", a[index_a], b[index_b],
           result[index_res], carry);

    index_a--;
    index_b--;
    index_res--;
  }

  for (int i = 0; i < max_len - min_len; i++) {
    if (len_a > len_b) {
      adder(a[index_a], '0', &result[index_res], &carry);

      printf("a: %c b: %c res: %c carry: %c\n", a[index_a], '0',
             result[index_res], carry);

      index_a--;
      index_res--;
    } else {
      adder('0', b[index_b], &result[index_res], &carry);

      printf("a: %c b: %c res: %c carry: %c\n", '0', b[index_b],
             result[index_res], carry);

      index_b--;
      index_res--;
    }
  }

  if (carry == '1')
    result[0] = '1';
  else
    result++;

  return result;
}

int main(void) {
  char a[] = "1010";
  char b[] = "1011";

  char *result = addBinary(a, b);

  printf("%s\n", result);

  return 0;
}
