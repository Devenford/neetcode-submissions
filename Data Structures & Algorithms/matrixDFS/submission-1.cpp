#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &visit) {
        int ROWS = grid.size(), COLS = grid[0].size();

        if (r<0 || c<0 || r == ROWS || c == COLS || grid[r][c] || visit[r][c]) {
            return 0;
        }
        if (r==ROWS-1 && c==COLS-1) {
            return 1;
        }

        visit[r][c] = 1;

        int count = 0;
        count += dfs(grid, r+1, c, visit);
        count += dfs(grid, r-1, c, visit);
        count += dfs(grid, r, c+1, visit);
        count += dfs(grid, r, c-1, visit);

        visit[r][c] = 0;
        return count;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> visit(grid.size(), vector<int> (grid[0].size(), 0));
        return dfs(grid, 0, 0, visit);
    }
};
