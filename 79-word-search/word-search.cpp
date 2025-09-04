class Solution {
public:
int m;
int n;
vector<vector<bool>>visited;


    bool dfs(vector<vector<char>>& board, string &word,int i,int j, int k){
        if(k==word.size())return true;
        if(i<0|| j<0|| i>=m || j>=n||visited[i][j]|| board[i][j]!=word[k])return false;
        visited[i][j]=true;

        bool found=dfs(board,word,i+1,j,k+1)||dfs(board,word,i-1,j,k+1)||dfs(board,word,i,j+1,k+1)||dfs(board,word,i,j-1,k+1);
        visited[i][j]=false;
        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if( dfs(board,word,i,j,0))return true;
            }
        }
       
       return false;

    }
};