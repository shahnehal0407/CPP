class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string store = "";

        for (int i = 0; i < 9; i++) {
            store += (i + 1) + '0';
        }

        string s1 = to_string(low);
        string s2 = to_string(high);

        int startLen = s1.size();
        int endLen = s2.size();

        vector<int> ans;

        for (int len = startLen; len <= endLen; len++) {
            for (int i = 0; i + len <= 9; i++) {
                string temp = store.substr(i, len);
                int num = stoi(temp);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};