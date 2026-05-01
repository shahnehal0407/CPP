class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int m=mat[0].size();
        int n=mat.size();
        bool reverse_flag = true;


        for (int i=0;i<m;i++){
            traverse(mat,i,0,m,n,reverse_flag,ans );
            reverse_flag = !reverse_flag;
        }

        for(int i=1;i<n;i++){
              traverse(mat,m-1,i,m,n,reverse_flag,ans);
              reverse_flag = !reverse_flag;
        }

        return ans;
    }



    void traverse(vector<vector<int>>& mat,int col,int row,int m, int n,bool reverse_flag,vector<int> & ans){
        int i=col;
        int j=row;
        vector<int>temp;
        while(j<n && i>=0){
            temp.push_back(mat[j][i]);
            i--;
            j++;
        }
        if(reverse_flag)reverse(temp.begin(),temp.end());

        i=col;
        j=row;
        int k=0;
        while(j<n && i>=0){
           mat[j][i]=temp[k];
            i--;
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            ans.push_back(temp[k]);
        }
    }
};