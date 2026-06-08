class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> st;

        for (string x : supplies) {
            st.insert(x);
        }

        vector<int> made(recipes.size(), 0);

        bool changed = true;

        while (changed) {
            changed = false;

            for (int i = 0; i < recipes.size(); i++) {
                if (made[i]) continue;

                bool possible = true;

                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (st.find(ingredients[i][j]) == st.end()) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    ans.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    made[i] = 1;
                    changed = true;
                }
            }
        }

        return ans;
    }
};