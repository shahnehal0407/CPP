class Solution {
public:

    vector<string>result;
    vector<string>mapping={
        "","","abc","def","ghi","jkl","mno",
"pqrs","tuv","wxyz"    };


void str(string digits, int i, string curr){
    if(i==digits.size()){
        result.push_back(curr);
        return;
    }
    string letters= mapping[digits[i] - '0'];
    for(char c: letters){
        str(digits,i+1,curr+c);
    }
}




    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string curr;
        str(digits,0,curr);
        return result;
    }
};