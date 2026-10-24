#include<vector>
#include<utility>
#include<unordered_set>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<bool>> &ocean, vector<vector<int>> &heights) {
        ocean[r][c] = true;
        for(vector<int> &direc : directions) {
            int newr = r + direc[0], newc = c + direc[1];
            if (newr >= 0 && newc >= 0 && newr < heights.size() && newc < heights[0].size() && heights[newr][newc] >= heights[r][c] && !ocean[newr][newc]) {
                dfs(newr, newc, ocean, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        // coordinates of cell that can reach the pacific
        vector<vector<bool>> pacific(m, vector<bool> (n, false)); 
        // coordinates of cell that can reach the atlantic
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        
        // dfs check for pacific border cells
        for(int c = 0; c < n; c++) {
            dfs(0, c, pacific, heights);
        }
        for(int r = 1; r<m; r++) {
            dfs(r, 0, pacific, heights);
        }

        // dfs check for atlantic border cells
        for(int c = 0; c < n; c++) {
            dfs(m-1, c, atlantic, heights);
        }
        for(int r = 0; r < m-1; r++) {
            dfs(r, n-1, atlantic, heights);
        }

        vector<vector<int>> sol;
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    sol.push_back({r, c});
                }
            }
        }

        return sol;
    }
};
