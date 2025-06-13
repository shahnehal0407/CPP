class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk;
        int n = a.size();

        for (int i = 0; i < n; ++i) {
            int curr = a[i];
            bool destroyed = false;

            while (!stk.empty() && stk.top() > 0 && curr < 0) {
                if (stk.top() < abs(curr)) {
                    stk.pop(); 
                    continue;
                } else if (stk.top() == abs(curr)) {
                    stk.pop(); 
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed)
                stk.push(curr);
        }

        // prepare result
        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
