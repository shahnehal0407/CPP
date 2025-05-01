class Solution {
public:
    int minAddToMakeValid(string s) {
        int count_left=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count_left++;
            else if (s[i]==')' && count_left!=0) count_left--;
            else ans++;

        }
         return  ans+count_left;
       
        }
};