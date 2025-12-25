class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;

        map<int,int>store;

        for(int i=0;i<nums.size();i++){
            store[nums[i]]++;
        }
        for(auto it = store.begin();it!=store.end();++it){
            int start = it->first;
            int freq= it->second;

            if(freq>0){
                for(int i=0;i<k;i++){
                    if(store[start+i]<freq)return false;
                    store[start+i]-=freq;
                }
            }


        }
        return true;
    }
};