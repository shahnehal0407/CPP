class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        if(m==0|| n==0)return m==0?text1: text2;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){ans+=text1[i-1];j--; i--;}
            else if(dp[i-1][j]>dp[i][j-1]){
               ans+=text1[i-1]; i--;
            }else {
                ans+=text2[j-1];
                j--;

            }
        }

      while(i>0){
        ans+=text1[i-1];
        i--;
      }
    
          while(j>0){
        ans+=text2[j-1];
        j--;
      }
      reverse(ans.begin(),ans.end());
    return ans;

    }
};