class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>left(s.size(),-1);
        vector<int>right(s.size(),-1);
        vector<int>prefix(s.size(),0);
        prefix[0] = (s[0] == '*');
        for (int i=1;i<s.size();i++){
            prefix[i]=prefix[i-1]+(s[i]=='*');
        }
        int c=-1;
        for (int i=0;i<s.size();i++){
            if(s[i]=='|')c=i;
            left[i]=c;

    }
    c=-1;
    for (int i=s.size()-1;i>=0;i--){
            if(s[i]=='|')c=i;
   
        right[i]=c;
        
    }
    vector<int>ans;

    for (int i=0;i<queries.size();i++){
        if(left[queries[i][1]] == -1 || right[queries[i][0]] == -1 || left[queries[i][1]]<= right[queries[i][0]]){ans.push_back(0);}
        else{
        ans.push_back(prefix[left[queries[i][1]]]-prefix[right[queries[i][0]]]);  
        }  
    }
    return ans;
    }
};