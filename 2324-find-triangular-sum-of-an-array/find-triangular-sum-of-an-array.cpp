class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>a(nums.begin(),nums.end());
        while(a.size()>1){
            vector<int>b;
            for(int i=0;i<a.size()-1;i++){
                b.push_back(((a[i]+a[i+1])%10));
            }
            a=b;
        }
        int ans=a[0];
        return ans;
        
    }
};