#include<vector>
#include<iostream>
using namespace std;

class Solution {
    int maxArea = 0, rows, cols;
    //change visited island square to '2'
    void dfs(vector<vector<int>> &grid, int r, int c, int &ar) {
        if (r<0 || c<0 || r==rows || c==cols || grid[r][c]==0 || grid[r][c]==2) {
            return;
        }

        grid[r][c] = 2;
        ar++;
        dfs(grid, r+1, c, ar);
        dfs(grid, r-1, c, ar);
        dfs(grid, r, c+1, ar);
        dfs(grid, r, c-1, ar);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]==1) {
                    int ar = 0;
                    dfs(grid, i, j, ar);
                    if (ar > maxArea) {
                        maxArea = ar;
                    }
                }
            }
        }

        return maxArea;
    }
};
