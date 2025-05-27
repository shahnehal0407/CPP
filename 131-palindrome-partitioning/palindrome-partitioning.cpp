class Solution {
public:

bool isPalindrome(const string& s) {
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void backtrack(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);  // Add the current partition path
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            string substr = s.substr(start, end - start + 1);
            if (isPalindrome(substr)) {
                path.push_back(substr);
                backtrack(s, end + 1, path, result);
                path.pop_back();  // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    
    }
};