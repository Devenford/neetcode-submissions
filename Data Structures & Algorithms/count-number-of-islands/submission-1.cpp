#include<vector>
#include<iostream>
using namespace std;

class Solution {
    int islandCount = 0, rows, cols;
    //change visited island square to '2'
    void dfs(vector<vector<char>> &grid, int r, int c) {
        if (r<0 || c<0 || r==rows || c==cols || grid[r][c]=='0' || grid[r][c]=='2') {
            return;
        }

        grid[r][c] = '2';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]=='1') {
                    dfs(grid, i, j);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
