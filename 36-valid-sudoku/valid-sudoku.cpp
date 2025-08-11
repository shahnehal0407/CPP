class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9; // Sudoku size

        // Check rows
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> store;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                store[board[i][j]]++;
                if (store[board[i][j]] > 1) return false;
            }
        }

        // Check columns
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> store;
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') continue; 
                store[board[j][i]]++;
                if (store[board[j][i]] > 1) return false;
            }
        }

        // Check 3×3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_map<char, int> store;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (c == '.') continue;
                        store[c]++;
                        if (store[c] > 1) return false;
                    }
                }
            }
        }

        return true; 
    }
};
