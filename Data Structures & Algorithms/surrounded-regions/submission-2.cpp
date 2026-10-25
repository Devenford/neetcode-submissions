// Without the visit matrix (mark each visited 'O' cell with another character, like 'V' for visited)
#include<vector>
using namespace std;

class Solution {
    // a cell is on the edge of the board if row = m-1 or column = n-1
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<char>> &board) {
        if (board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'V';
        for (vector<int> &direc : directions) {
            int newr = r + direc[0], newc = c + direc[1];
            if (newr >=0 && newc >=0 && newr < board.size() && newc < board[0].size() && board[newr][newc] != 'V') {
                dfs(newr, newc, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        // Perform DFS from each 'O' cell on the boundary
        for(int c=0; c<n; c++) {
            dfs(0, c, board);
            dfs(m-1, c, board);
        }
        for(int r=1; r < m-1; r++) {
            dfs(r, 0, board);
            dfs(r, n-1, board);
        }

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                // if we weren't able to visit the 'O' cell by performing dfs from the 'O' cells on the boundary, then it's a part of a surrounded region
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if (board[r][c] == 'V') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
