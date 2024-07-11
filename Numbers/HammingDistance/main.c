int hammingDistance(int x, int y) {
  // distance between the first different bit of x and y

  int distance = 0;

  while (x > 0 || y > 0) {
    if ((x & 1) != (y & 1)) {
      distance++;
    }
    x >>= 1;
    y >>= 1;
  }

  return distance;
}

/*
int hammingDistance(int x, int y) {
    int xor = x^y;
    int count =0;
    while(xor!=0)
    {
        if(xor&1)
        {
            count++;
        }
        xor=xor>>1;
    }
    return count;
}
*/
