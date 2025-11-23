class Solution {
public:
    int reverse(int x) {
        long long out = 0;      // use long long to detect overflow
        
        while (x != 0) {
            int d = x % 10;
            out = out * 10 + d;

            // check if out is outside 32-bit signed integer range
            if (out > INT_MAX || out < INT_MIN) 
                return 0;

            x /= 10;
        }
        return (int)out;
    }
};
