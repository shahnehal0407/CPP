class Solution {
public:

    void recc(vector<string> &ans, string curr, int n){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        recc(ans,curr+'1',n);
        if(curr.empty() || curr.back()=='1'){
            recc(ans,curr+'0',n);
        }

    }


    vector<string> validStrings(int n) {
    vector<string>ans;
    recc(ans,"",n);
    return ans;

    }
};