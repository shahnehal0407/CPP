class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1;
        string ans="";
        while(i>=0){

            while(i>=0 && s[i]==' ')i--;
            if(i<0)break;
            string temp="";
            while(i>=0 && s[i]!=' '){
                temp=s[i]+temp;
                i--;
            }
            if(ans.size()>0)ans+=' ';
            ans+=temp;

        }
            return ans;
    }
};