class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int back=0;
        int i=path.size()-1;

        while(i>=0){
            string temp="";
            while(i>=0 && path[i]!='/'){
                temp=path[i]+temp;
                i--;
            }

            i--;
            if(temp=="" || temp==".")continue;
            else if(temp=="..")back++;
            else if(back>0)back--;
            else {
                ans='/'+temp+ans;
            }

        }
        if(ans=="")return "/";
        else return ans;
        
    }
};