class Solution {
public:
    string countAndSay(int n) {
        string s="1";
   for(int i=1;i<n;i++){
    s = seq(s);
   }
   return s;
    }

    string seq(string c){
        string ans ="";
        int count =1;
        for(int i=1;i<=c.size();i++){
            if(c[i]==c[i-1])count++;
            else {
                ans= ans+ to_string(count)+c[i-1];
                count=1;
              }
        }
         return ans;
    }
};