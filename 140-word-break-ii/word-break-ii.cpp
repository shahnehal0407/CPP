class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        // 1) Compute max word size (same as your logic)
        int maxsize = 0;
        for (int i = 0; i < (int)wordDict.size(); ++i) {
            maxsize = max(maxsize, (int)wordDict[i].size());
        }

        // 2) DP over prefixes: dp[i] = can break s[0..i-1]
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // For reconstruction: prev[i] will store all j such that
        // s[j..i-1] is a dict word and dp[j] is true.
        vector<vector<int>> prev(n + 1);

        for (int i = 0; i < n; ++i) {
            // If current prefix cannot be formed, we still try substrings,
            // but they'll only be recorded if dp[i+1-t] is true.
            int t = 1;
            while (t <= maxsize && i + 1 - t >= 0) {
                int start = i + 1 - t;                 // substring start
                // substring s[start..i]
                string sub = s.substr(start, t);
                // SAME MEMBERSHIP CHECK STYLE AS YOUR CODE:
                if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end() && dp[start]) {
                    dp[i + 1] = true;                   // we can reach i+1
                    prev[i + 1].push_back(start);       // remember split
                }
                ++t;
            }
        }

        vector<string> ans;
        if (!dp[n]) return ans; // no sentences

        // 3) Backtrack all sentences from prev[].
        vector<string> path;   // collect words in reverse order (last to first)
        buildSentences(n, prev, s, path, ans);
        return ans;
    }

private:
    void buildSentences(int i,
                        const vector<vector<int>>& prev,
                        const string& s,
                        vector<string>& path,
                        vector<string>& ans) {
        if (i == 0) {
            // path holds words from right to left; build sentence in forward order
            string sentence;
            for (int k = (int)path.size() - 1; k >= 0; --k) {
                sentence += path[k];
                if (k) sentence += ' ';
            }
            ans.push_back(sentence);
            return;
        }
        for (int j : prev[i]) {
            // word is s[j..i-1]
            path.push_back(s.substr(j, i - j));
            buildSentences(j, prev, s, path, ans);
            path.pop_back();
        }
    }
};
