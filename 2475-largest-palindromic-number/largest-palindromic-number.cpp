class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>f(10,0);
        for(int i=0;i<num.size();i++){
            f[num[i]-'0']++;
        }


        string left="";

        for(int d=9;d>=0;d--){
        int pairs=f[d]/2;
        if(pairs>0){
            if(d==0 && left.empty())continue;
            left.append(pairs,d+'0');
        }
        }
        string mid="";
        for(int d=9;d>=0;d--){
            if(f[d]%2==1){
            mid=(d+'0');
            break;
            }
           
        }
        if(left.empty()){
         if(mid!="")return mid;
         else return "0";
        }
       
        string right=left;
        reverse(left.begin(),left.end());
        return right+mid+left;

    }
};