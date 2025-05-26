class Solution {
public:



void backtrack(vector<string> & ans,string current,int left_count, int right_count,int n){

    if(current.size()==n*2)ans.push_back(current);
    if(left_count<n) backtrack(ans,current+"(",left_count+1,right_count,n);
    if(right_count<left_count)backtrack(ans,current+")",left_count,right_count+1,n);

}

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans,"",0,0,n);
        return ans;
       }

};