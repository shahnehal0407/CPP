class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> store;

        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                store[word[i]] = i;   // last lowercase index
            }
        }

        int ans = 0;
        unordered_set<char> seenUpper;

        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                char lower = tolower(word[i]);

                if (seenUpper.find(lower) == seenUpper.end()) {
                    seenUpper.insert(lower);   // only check first uppercase

                    if (store.find(lower) != store.end() && store[lower] < i) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};