class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            map<int,vector<int>>store;

            for(int i=0;i<arr.size();i++){
                store[abs(arr[i]-x)].push_back(arr[i]);

            }

            vector<int>ans;
            for(int i=0;i<store.size();i++){
                for(int j=0;j<store[i].size();j++){
                    if(ans.size()<k)ans.push_back(store[i][j]);
                    else break;
                }
            }

            sort(ans.begin(),ans.end());
            return ans;
    }
};