class Solution {
public:

    void nextPermutationString(string& s) {
        int n = s.size();

        int i = n - 2;

        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (s[j] <= s[i]) {
                j--;
            }

            swap(s[i], s[j]);
        }

        reverse(s.begin() + i + 1, s.end());
    }

    int getMinSwaps(string num, int k) {
        string target = num;

        // Step 1: Find kth smallest greater number
        while (k--) {
            nextPermutationString(target);
        }

        int swaps = 0;
        int n = num.size();

        // Step 2: Convert num into target using adjacent swaps
        for (int i = 0; i < n; i++) {

            if (num[i] == target[i]) {
                continue;
            }

            int j = i + 1;

            // Find the character target[i] in current num
            while (j < n && num[j] != target[i]) {
                j++;
            }

            // Bring num[j] to index i using adjacent swaps
            while (j > i) {
                swap(num[j], num[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};