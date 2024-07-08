#include <stdbool.h>
#include <stdio.h>

int getSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  if (n == 1)
    return true;
  else if (n == 4)
    return false;

  return isHappy(getSum(n));
}

int main(void) {
  int n = 2;
  printf("%d\n", isHappy(n));
  return 0;
}

/*
int next_n(int n){
    int r = 0;
    while(n !=0){
        int d = n % 10;
        n /= 10;
        r += d * d;
    }
    return r;
}

bool contains(int *history, int size, int n){
    for(int i = 0; i < size; i++){
        if(history[i] == n){
            return true;
        }
    }
    return false;
}

bool isHappy(int n) {

    int history[10000];
    int size = 0;

    while(!contains(history, size, n)){
        history[size] = n;
        size++;

        n = next_n(n);

    }
    return n == 1;
}
*/
