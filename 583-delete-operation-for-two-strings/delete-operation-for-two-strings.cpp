class Solution {
public:
    int minDistance(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        if(m==0|| n==0)return m==0?n:m;

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       return m+n-2*dp[n][m];
    }
};