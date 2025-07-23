class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
int n=heights.size();
int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;


        dist[0][0]=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto[d,cell]=pq.top();
            int x= cell.first;
            int y=cell.second;
            pq.pop();
            if (x == n - 1 && y == m - 1) return d;
            for(int i=0;i<4;i++){
                int r=x+dx[i];
                int c= y+dy[i];
                if(r >= 0 && c >= 0 && r < n && c < m){
                    int effort=max(d,abs(heights[r][c] - heights[x][y]));
                                        if (effort < dist[r][c]) {
                        dist[r][c] = effort;
                        pq.push({effort, {r, c}});
                    }
                }
            }
        }


  return 0;

    }
};