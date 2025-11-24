class Solution {
public:



    bool ok(string &s,int l, int r){
        int len = r-l;
        if(len<=0 || len>3)return false;
        if(s[l]=='0' && len>1)return false;
        int num =0;
        for(int i=l;i<r;i++){
            num=num*10+ (s[i]-'0');    
        }
        return num<=255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n=s.size();
        if(n<3 || n>12)return ans;
        for(int i=1;i<=3 && i<=n;i++){
            for(int j=i;j<=i+3 && j<=n;j++){
                for(int k=j;k<=j+3 && k<=n;k++){
                    if(!ok(s,0,i)) continue;
                    if(!ok(s,i,j)) continue;
                    if(!ok(s,j,k)) continue;
                    if(!ok(s,k,n)) continue;

                    string ip = s.substr(0,i)+"."+s.substr(i,j-i)+"."+s.substr(j,k-j)+"."+s.substr(k);
                    ans.push_back(ip);
                }
            }
        }


    return ans;


    }
};