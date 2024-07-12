bool checkPerfectNumber(int num) {
  int sum = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      sum += i;
      if (i * i != num)
        sum += num / i;
    }
  }
  return sum == num;
}

/*
int i,sum=1;
  if(num<=1){
      return false;
  }
  for(i=2;i*i<=num;i++){
      if(num%i==0){
          sum+=i;
          if(i!=num/i){
              sum+=num/i;
          }
      }
  }
  return sum==num;
*/
