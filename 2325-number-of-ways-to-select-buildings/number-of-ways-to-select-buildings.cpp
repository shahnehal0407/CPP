class Solution {
public:
    long long numberOfWays(string s) {
        long long total0=0,total1=0;

        for(char c : s){
            if(c=='0')total0++;
            else total1++;
        }
        long long left1=0,left0=0;
long long ans=0;
        for(char c:s){
            if(c=='0'){
                total0--;
                ans+=left1*total1;
                left0++;
            }
            else {
                total1--;
                ans+=left0*total0;
                left1++;
            }
        }
        return ans;
    }
};