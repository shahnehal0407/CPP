class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> blocks(26);

        // Collect block lengths
        for (int i = 0; i < s.size();) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            blocks[s[i] - 'a'].push_back(j - i);
            i = j;
        }

        int ans = -1;

        for (int c = 0; c < 26; c++) {
            if (blocks[c].empty()) continue;

            sort(blocks[c].begin(), blocks[c].end(), greater<int>());

            int L1 = blocks[c][0];
            int L2 = blocks[c].size() > 1 ? blocks[c][1] : 0;
            int L3 = blocks[c].size() > 2 ? blocks[c][2] : 0;

            ans = max(ans, L1 - 2);
            ans = max(ans, min(L1 - 1, L2));
            ans = max(ans, L3);
        }

        return ans <= 0 ? -1 : ans;
    }
};
