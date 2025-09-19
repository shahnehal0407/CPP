#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> store; // 2D grid
    int r;
    int c = 26;

    Spreadsheet(int rows) {
        r = rows;
        store.assign(r, vector<int>(c, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; // 1-based to 0-based
        store[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        store[row][col] = 0;
    }
    
    int getValue(string formula) {
        // Remove the leading '='
        if (!formula.empty() && formula[0] == '=') {
            formula = formula.substr(1);
        }

        int sum = 0;
        string token;
        stringstream ss(formula);

        while (getline(ss, token, '+')) {
            if (isdigit(token[0])) {
                sum += stoi(token);
            } else {
                int col = token[0] - 'A';
                int row = stoi(token.substr(1)) - 1;
                sum += store[row][col];
            }
        }
        return sum;
    }
};
