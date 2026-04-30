class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1 || numRows >= s.size()) return s;
            vector<string>rows(numRows);
        int curRows=0;
        bool down=false;
        for(int i=0;i<s.size();i++){
            rows[curRows]+=s[i];
            if(curRows== 0 || curRows==numRows-1)
            down=!down;

            curRows+=down?1:-1;

        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=rows[i];
        }

        return ans;
    }
};