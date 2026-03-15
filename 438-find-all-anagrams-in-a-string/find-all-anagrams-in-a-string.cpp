class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int>freq1(26,0),freq2(26,0);
        vector<int>res;
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;

        }
        for(int i=0;i<s2.size();i++){
            freq2[s2[i]-'a']++;

            if(i>=s1.size())freq2[s2[i-s1.size()]-'a']--;
            if(freq1==freq2)res.push_back(i-s1.size()+1);
        }
        return res;
    }
};