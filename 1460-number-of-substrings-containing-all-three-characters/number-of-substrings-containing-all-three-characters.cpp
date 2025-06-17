class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>store(3,0);
        int j=0;
        int ans=0;
        for(int i =0;i<s.size();i++){
         store[s[i]-'a']++;

         while(store[0]>0 && store[1]>0 && store[2]>0){
            ans+=s.size()-i;
            store[s[j]-'a']--;
            j++;
         }
        }
        return ans;
    }
};