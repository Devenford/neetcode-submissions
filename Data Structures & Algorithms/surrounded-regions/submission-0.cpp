#include<vector>
using namespace std;

class Solution {
    // a cell is on the edge of the board if row = m-1 or column = n-1
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &visit) {
        if (board[r][c] != 'O') {
            return;
        }

        visit[r][c] = true;
        for (vector<int> &direc : directions) {
            int newr = r + direc[0], newc = c + direc[1];
            if (newr >=0 && newc >=0 && newr < board.size() && newc < board[0].size() && !visit[newr][newc]) {
                dfs(newr, newc, board, visit);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        // Perform DFS from each 'O' cell on the boundary
        for(int c=0; c<n; c++) {
            dfs(0, c, board, visit);
            dfs(m-1, c, board, visit);
        }
        for(int r=1; r < m-1; r++) {
            dfs(r, 0, board, visit);
            dfs(r, n-1, board, visit);
        }

        for(int r = 0; r < m-1; r++) {
            for(int c = 0; c < n-1; c++) {
                // if we weren't able to visit the 'O' cell by performing dfs from the 'O' cells on the boundary, then it's a part of a surrounded region
                if (!visit[r][c] && board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
