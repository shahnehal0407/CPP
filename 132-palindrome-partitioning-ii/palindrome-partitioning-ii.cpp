class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i,int j,string &s, vector<int>& dp){
        if(i==j) return 0;
        if(ispalindrome(i,j,s)) return 0;

        if(dp[i]!=-1) return dp[i];

        int mini = INT_MAX;
        for(int ind=i; ind<j; ind++){
            if(ispalindrome(i,ind,s)){
                int cuts = 1 + f(ind+1,j,s,dp);
                mini = min(mini, cuts);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n-1, s, dp);
    }
};
