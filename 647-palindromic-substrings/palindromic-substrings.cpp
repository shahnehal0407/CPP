class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            expand(s,i,i,ans);
            expand(s,i,i+1,ans);
        }
        return ans;
    }
    void expand(string s, int l, int r, int & ans){
        while(l>=0 && r<=s.size()-1 && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
    }
   
};