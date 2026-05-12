class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> store;
        
        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < s.size()) {
            store[s[j]]++;

            if (store.size() == (j - i + 1)) {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (store.size() < (j - i + 1)) {
                while (store.size() < (j - i + 1)) {
                    store[s[i]]--;

                    if (store[s[i]] == 0) {
                        store.erase(s[i]);
                    }

                    i++;
                }

                j++;
            }
        }

        return ans;
    }
};