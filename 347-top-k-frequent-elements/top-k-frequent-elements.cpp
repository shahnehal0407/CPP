class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>store;

        for(int i=0;i<nums.size();i++){
            store[nums[i]]++;

        }


    vector<pair<int,int>>s;
    vector<int>ans;

    for(pair<int,int>p:store){
        s.push_back({p.second,p.first});
    }

    sort(s.begin(),s.end());
        int n=s.size();
    for(int i=n-1;i>=n-k;i--){
        ans.push_back(s[i].second);
    }
        return ans;
    }
};