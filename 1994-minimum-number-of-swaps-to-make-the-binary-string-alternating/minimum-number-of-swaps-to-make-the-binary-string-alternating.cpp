class Solution {
public:
    int minSwaps(string s) {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zero++;
            else one++;
        }

        if (abs(zero - one) > 1) return -1;

        int m1 = 0; // pattern: 101010...
        int m2 = 0; // pattern: 010101...

        for (int i = 0; i < s.size(); i++) {
            if ((i % 2 == 0 && s[i] != '1') || (i % 2 == 1 && s[i] != '0')) {
                m1++;
            }

            if ((i % 2 == 0 && s[i] != '0') || (i % 2 == 1 && s[i] != '1')) {
                m2++;
            }
        }

        if (one > zero) {
            return m1 / 2;
        }
        else if (zero > one) {
            return m2 / 2;
        }

        return min(m1, m2) / 2;
    }
};