class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>store;

        int num=0;
        string cur="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))num=num*10+(s[i]-'0');

            else if(s[i]=='['){
                store.push({cur, num});
                num=0; 
                cur="";
                }
            else if(s[i]==']'){
                string temp="";
            for(int i=0;i<store.top().second;i++){
                temp+=cur;
            }
            cur="";
            cur+=store.top().first+temp;
            store.pop();
    
            }
            else cur+=s[i];
        }

        return cur;
    }
};