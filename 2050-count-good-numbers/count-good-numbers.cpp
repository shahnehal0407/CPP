class Solution {
public:
    int md = (int)1e9+7;
    long long power(long long x, long long n){
        if(n==0) return 1;
        long long res = power(x, n/2);
        res = (res*res)%md;
        if(n%2) res = (res*x)%md;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long no = n/2;
        long long ne = (n+1)/2;
        return (power(5, ne)*power(4, no))%md;
    }
};