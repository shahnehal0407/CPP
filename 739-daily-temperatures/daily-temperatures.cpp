class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        vector<int>ans(t.size(),0);

        for(int i=t.size()-1;i>=0;i--){
            while(!st.empty() && t[i]>=st.top().first )st.pop();
            if(!st.empty())ans[i]=st.top().second -i;
            st.push({t[i],i});
        }

        return ans;
    }
};