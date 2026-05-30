class Solution {
public:
    long long C2(long long x) {
        if(x < 2) return 0;
        return x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        ans += C2(n + 2);              // total without limit
        ans -= 3 * C2(n - limit + 1);  // subtract one child invalid
        ans += 3 * C2(n - 2 * limit);  // add back two children invalid
        ans -= C2(n - 3 * limit - 1);  // subtract three children invalid

        return ans;
    }
};