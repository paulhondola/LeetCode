#include <stdio.h>

int mySqrt(int x) {
    unsigned long sqrt = 0;
    unsigned long square = 0;
    while (square <= x)
    {
        sqrt++;
        square = sqrt * sqrt;
    }
    return sqrt - 1;
}

/*
int mySqrt(int x) {
    if(x==0)
    return 0;
    int l=1,r=x;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mid<=x/mid){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    return ans;

}
*/

int main(void)
{
    int x = 4;
    printf("The square root of %d is %d\n", x, mySqrt(x));
    return 0;
}
