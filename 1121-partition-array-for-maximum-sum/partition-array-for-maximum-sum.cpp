class Solution {
public:

    int f(int i,int k,int j,vector<int>& arr,vector<int>& dp){

        if(i > j) return 0;

        int len=0;
        if(dp[i] != -1) return dp[i];
        int maxi=INT_MIN;
        int ans=INT_MIN;
        for(int ind=i; ind <= min(i+k-1, j); ind++){
            len++;
            maxi=max(arr[ind],maxi);

            int cost=len*maxi+f(ind+1,k,j,arr,dp);
            ans=max(ans,cost);
        }

            return dp[i]=ans;
    }




    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(0,k,arr.size()-1,arr,dp);
    }
};