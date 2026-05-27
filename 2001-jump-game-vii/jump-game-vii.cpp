class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool>dp(s.size(),false);
            dp[0]=true;

            int r=0;
        for(int i=0;i<s.size();i++){
            if(i-minJump>=0 && dp[i-minJump])r++;
            if(i-maxJump-1>=0 && dp[i-maxJump-1])r--;
                if(s[i]=='0' && r>0)dp[i]=true;
            }


return dp[s.size()-1];
    }
};