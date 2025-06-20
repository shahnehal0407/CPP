bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int>ans;

    vector<pair<int, int>> freqVec(freq.begin(), freq.end());
    sort(freqVec.begin(), freqVec.end(), compare);
    for(int i=0;i<k;i++){
        ans.push_back(freqVec[i].first);
    }
        return ans;
        
    }
};