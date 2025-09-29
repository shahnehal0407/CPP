class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxsize=0;
        for(int i=0;i<wordDict.size();i++){
            maxsize=max(maxsize,(int)wordDict[i].size());
        }
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;

        for(int i=0;i<n;i++){
            int t=1;
            bool a=false;
            while(t<=maxsize && i + 1 - t >= 0){
                string sub = s.substr(i + 1 - t, t);
if(find(wordDict.begin(),wordDict.end(),sub)!=wordDict.end() && dp[i+1-t]){a=true; break;}          t++;
            }
            dp[i+1]=a;
       
        }
        return dp[n];
    }
};