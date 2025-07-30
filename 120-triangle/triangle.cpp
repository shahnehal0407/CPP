class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m = triangle[n-1].size();
        vector<int>last(m,-1);
        for(int i=0;i<m;i++){
             last[i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>dp(i+1,-1);
            for(int j=i;j>=0;j--){
                dp[j]= triangle[i][j]+min(last[j+1], last[j]);

            }
            last=dp;
        }

        
         return last[0];
    }
};