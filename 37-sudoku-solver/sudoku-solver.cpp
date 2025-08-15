class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }


bool solve(vector<vector<char>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j = 0; j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValidSudoku(board,i,j,c)){
                        board[i][j]=c;

                        if(solve(board)==true)
                            return true;
                        else
                        board[i][j]='.';


                    }
                }
                        return false;
            }
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board,int row, int col, char c) {
        int n = 9; // Sudoku size

        // Check rows
        for (int i = 0; i < n; i++) {
                if (board[i][col] == c )
                return false;
       
 
        // Check columns
                if (board[row][i] == c )
                return false;
        
  

        // Check 3×3 sub-boxes
        if(board[3*(row/3)+ i/3][3*(col/3)+i%3]==c) return false;

        }
        return true;
        }
    };