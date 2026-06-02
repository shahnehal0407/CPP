class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;

                int mini=INT_MAX;
                int maxi=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                    mini=min(mini,freq[k]);
                    maxi=max(maxi,freq[k]);
                }}

            ans+=maxi-mini;
            }
        }
        return ans;
    }
};