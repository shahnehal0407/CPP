class Solution {
public:
    int characterReplacement(string s, int k) {

    vector<int>freq(26,0);
    int j=0;
    int ans=0;
    int count=0;

    for(int i=0;i<s.size();i++){
        freq[s[i] - 'A']++;
        count= max(count,freq[s[i] - 'A']);

        while(i-j+1- count>k){
            freq[s[j] - 'A']--;
            j++;
        }
       
       ans= max(ans, i-j+1);
    }
        



    return ans;


    }
};