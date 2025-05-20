class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> count(n+m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count[i]++;
                    count[n+j]++;
                }
            }
        }
        int servers=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(count[i]>1 || count[n+j]>1)
                    servers++;
                }
            }
        }
        return servers;
    }
};