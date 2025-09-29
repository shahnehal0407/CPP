class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxsize = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            maxsize = max(maxsize, (int)wordDict[i].size()); // take length of word
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string is valid

        for (int i = 0; i < n; i++) {
            int t = 1;  // substring length
            bool a = false;

            while (t <= maxsize && i + 1 - t >= 0) { // stay within bounds
                string sub = s.substr(i + 1 - t, t);
                if (dp[i + 1 - t] && find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                    a = true;
                    break; // found a valid split
                }
                t++;
            }
            dp[i + 1] = a;
        }

        return dp[n];
    }
};
