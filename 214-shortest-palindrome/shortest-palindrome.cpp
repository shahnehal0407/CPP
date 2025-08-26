class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";

        string r = s;
        reverse(r.begin(), r.end());
        r = s + '#' + r;   // build combined string

        vector<int> lps(r.size(), 0);
        int j = 0;

        for (int i = 1; i < r.size(); i++) {
            if (r[i] == r[j]) {
                j++;
                lps[i] = j;      // store current prefix length
            } else {
                if (j > 0) {
                    j = lps[j - 1];  // backtrack j
                    i--;             // retry with new j
                } else {
                    lps[i] = 0;
                }
            }
        }

        int longestPalPrefix = lps.back();
        string add = s.substr(longestPalPrefix);
        reverse(add.begin(), add.end());

        return add + s;
    }
};
