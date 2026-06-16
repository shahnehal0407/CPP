class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int ans=0;
        for(int n:st){
            int curr=0;
            int l=0;
            if(st.find(n-1)==st.end()){
                curr=n;
                l=1;
            
            while(st.find(curr+1)!=st.end()){
                l++;
                curr++;
            }
            }
            ans=max(ans,l);
        }
        return ans;
    }
};