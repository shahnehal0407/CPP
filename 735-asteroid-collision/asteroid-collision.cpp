class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> store;

        for(int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];

            if(curr < 0) {
                while(!store.empty() && store.top() > 0 && abs(curr) > store.top()) {
                    store.pop();
                }

                if(!store.empty() && store.top() > 0 && abs(curr) == store.top()) {
                    store.pop();
                }
                else if(store.empty() || store.top() < 0) {
                    store.push(curr);
                }
            }
            else {
                store.push(curr);
            }
        }

        vector<int> ans;
        while(!store.empty()) {
            ans.push_back(store.top());
            store.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};