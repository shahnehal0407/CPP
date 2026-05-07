class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>store;

        for(int i=0;i<words.size();i++){
            store[words[i]]++;
        }

        vector<pair<int,string>>v;

        for(pair<string,int>p:store){
            v.push_back({-(p.second),(p.first)});
        }

        sort(v.begin(),v.end());
        vector<string>ans;

    for(int i=0;i<k;i++){
        ans.push_back(v[i].second);
    }
    return ans;
    }
};