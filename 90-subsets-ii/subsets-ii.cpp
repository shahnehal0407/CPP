class Solution {
public:

void backtrack(vector<vector<int>>& ans,vector<int>& temp,vector<int>& k,int j){

    if(find(ans.begin(),ans.end(),temp)==ans.end()){ans.push_back(temp);}
    else return;
    
    for(int i=j;i<k.size();i++){
        temp.push_back(k[i]);
        backtrack(ans,temp,k,i+1);
            temp.pop_back();   }


      }

    vector<vector<int>> subsetsWithDup(vector<int>& k) {
        vector<vector<int>>ans;
        sort(k.begin(),k.end());
        vector<int> temp;
        backtrack(ans,temp,k,0);
        return ans;

    }
};