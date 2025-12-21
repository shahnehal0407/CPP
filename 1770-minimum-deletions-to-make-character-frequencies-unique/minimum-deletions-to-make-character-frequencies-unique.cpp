class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        unordered_set<int> used;
        int deletions = 0;

        // Step 2: Ensure all frequencies are unique
        for (auto &p : freq) {
            int f = p.second;

            // Reduce frequency until it becomes unique
            while (f > 0 && used.count(f)) {
                f--;
                deletions++;
            }

            if (f > 0) {
                used.insert(f);
            }
        }

        return deletions;
    }
};
