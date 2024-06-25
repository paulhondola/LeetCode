#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {
  int max_profit = 0;
  int min_price = prices[0];

  for (int i = 1; i < pricesSize; i++) {
    if (min_price > prices[i])
      min_price = prices[i];
    else if (prices[i] - min_price > max_profit)
      max_profit = prices[i] - min_price;
  }

  return max_profit;
}

int main(void) {
  const int n = 6;
  int prices[6] = {7, 1, 5, 3, 6, 4};
  printf("%d\n", maxProfit(prices, n));
  return 0;
}
