class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
            int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
           if(mat[j][i]==1){
            q.push({{j,i},0});
            vis[j][i]=1;
           }
           else  vis[j][i]=0;
        }
    }
     
     int drow[]={-1,0,1,0};
     int dcol[]={0,1,0,-1};


    while(!q.empty()){
            int r= q.front().first.first;
            int c=q.front().first.second;
              int dist= q.front().second;
              q.pop();
              ans[r][c]= dist;
              for(int i=0;i<4;i++){
                    int nrow= r+drow[i];
                    int ncol = c+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},dist+1});

                    }
                
              }
    }
    return ans;
    }

};