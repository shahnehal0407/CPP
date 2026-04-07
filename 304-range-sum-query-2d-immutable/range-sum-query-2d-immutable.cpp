class NumMatrix {
public:
    vector<vector<int>>p;
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();
        p.assign(n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                p[i][j]=mat[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++; c1++; r2++; c2++;
        return p[r2][c2]-p[r1-1][c2]-p[r2][c1-1]+p[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */