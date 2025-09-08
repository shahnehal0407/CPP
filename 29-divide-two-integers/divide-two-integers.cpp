class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0)sign = false;
        else if(dividend<=0 && divisor>0)sign = false;
        long n=labs(dividend);
        long d= labs(divisor);
        divisor=labs(divisor);
        long quotient=0;
        while(n>=d){
            int c=0;
            while(n>=(d<<(c+1))){
                c++;
            }
            quotient+=1<<c;
            n-=(d<<c);
        }
if(quotient==(1<<31)&& sign)return INT_MAX;
if(quotient==(1<<31)&& !sign)return INT_MIN;
return sign?quotient:-quotient;

    }
};