#include<vector>
#include<string>
using namespace std;

// Iterate column-wise and try to place a queen in each column while ensuring no other queen exists in the same row, left top diagonal, or left bottom diagonal. (Since the next column's queen hasn't been placed yet.)

class Solution {
    void dfs(int r, int c, int n, vector<string> &board, vector<vector<string>> &boards) { // r = row, c = col
        if (c == n) {
            if (r == 0) {
                boards.push_back(board);
            }
            return;
        }

        // row check
        for(int i = 1; c - i >= 0; i++) {
            if(board[r][c - i] == 'Q') {
                return;
            }
        }

        // left top diagonal check
        for(int i = 1; r - i >= 0 && c - i >= 0; i++) {
            if(board[r - i][c - i] == 'Q') {
                return;
            }
        }

        // left bottom diagonal check
        for(int i = 1; r + i < n && c - i >= 0; i++) {
            if(board[r + i][c - i] == 'Q') {
                return;
            }
        }

        board[r][c] = 'Q';
        for (int i=0; i<n; i++) { // try placing a queen in each row in the next column
            dfs(i, c+1, n, board, boards);
        }
        board[r][c] = '.'; // backtrack, i.e. once you've tried all possible valid arrangements with a queen at the current col and row, remove it so that you can try placing the queen in the next row (within the same column)
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> boards;
        string temp;
        for(int i=0; i<n; i++) {
            temp.push_back('.');
        }

        for(int i=0; i<n; i++) { // for each row in the first column
            vector<string> board(n, temp);
            dfs(i, 0, n, board, boards);
        }

        return boards;
    }
};
