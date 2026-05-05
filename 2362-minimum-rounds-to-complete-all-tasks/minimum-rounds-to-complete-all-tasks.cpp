class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;

        for (int task : tasks) {
            freq[task]++;
        }

        int rounds = 0;

        for (auto p : freq) {
            int count = p.second;

            if (count == 1) {
                return -1;
            }

            rounds += ceil(count/3.0);
        }

        return rounds;
    }
};