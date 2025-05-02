// class Solution {
// public:
//     string longestPrefix(string s) {
        
//         string ans="";
//         for(int i=1;i<s.size();i++){
//             string q = s.substr(0,i);
            
//             string r = s.substr(s.size()-i,i);
//             if( q == r)  ans = q;
//         }
//         return ans;
//     }
    
// };

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);  // lps[i] = length of longest prefix-suffix for s[0..i]
        int len = 0;

        for (int i = 1; i < n; ++i) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];
            if (s[i] == s[len])
                len++;
            lps[i] = len;
        }

        return s.substr(0, lps[n - 1]);
    }
};
