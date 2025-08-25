class Solution {
public:
    bool ispalindrome(int i,int j,string & s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;

        }
        return true;

    }

    int f(int i,int j,string & s, vector<int>& dp){
        if(i==j)return 0;
         if(ispalindrome(i,j,s)) return 0;
        int mini=INT_MAX;
        if(dp[i]!=-1)return dp[i];
        for(int ind=i;ind<j;ind++){
            if(ispalindrome(i,ind,s)){
                int c=1+f(ind+1,j,s,dp);
                 mini=min(c,mini);

            }
            
        }
        return dp[i]=mini;
    }



    int minCut(string s) {
       vector<int>dp(s.size(),-1);
        return f(0,s.size()-1,s,dp);
    }
};