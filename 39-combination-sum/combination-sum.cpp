class Solution {
public:

void backtrack(vector<int>& k, int target,vector<int>& temp,int n,vector<vector<int>>& ans,int j){
    if (target==0) {ans.push_back(temp); return;}
    if(target<0) return ;
    for(int i=j;i<n;++i){
        temp.push_back(k[i]);
        backtrack(k,target-k[i],temp,n,ans,i);
        temp.pop_back();
    }
}



    vector<vector<int>> combinationSum(vector<int>& k, int target) {
   int n= k.size();
    vector<vector<int>> ans;
    vector<int> temp;
    
    backtrack(k,target,temp,n,ans,0);
    return ans;


        
    }
};