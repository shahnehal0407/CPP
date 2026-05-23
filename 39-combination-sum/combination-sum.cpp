class Solution {
public:
    void backtrack(vector<int>& k, int t,vector<int>& temp,vector<vector<int>>& ans,int j){
        if(t==0){ans.push_back(temp);return;}
        if(t<0)return;

        for(int i=j;i<k.size();i++){
            temp.push_back(k[i]);
            backtrack(k,t-k[i],temp,ans,i);
            temp.pop_back();

        }
    }






    vector<vector<int>> combinationSum(vector<int>& k, int t) {
        vector<vector<int>>ans;
        vector<int>temp;

        backtrack(k,t,temp,ans,0);

        return ans;
    }
};