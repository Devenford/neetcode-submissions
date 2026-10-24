// BFS, since we're finding the shortest path for each land cell
// Multi-Source BFS (Each treasure chest square is a source, i.e. we start from each treasure chest and expand outward. Push every source cell into the queue at the start.
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q; // <row, col>
        
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // process level-by-level
        int level = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for(int i=0; i < qsize; i++) {
                pair<int, int> p = q.front();
                int r = p.first, c = p.second;
                q.pop();

                for(vector<int> direc : directions) {
                    if (r + direc[0] >= 0 && r + direc[0] < m && c + direc[1] >= 0 && c + direc[1] < n && grid[r + direc[0]][c + direc[1]] == INT_MAX) {
                        q.push({r + direc[0], c + direc[1]});
                        grid[r + direc[0]][c + direc[1]] = level + 1;
                        // a visited matrix isn't required since we're marking each land cell with level + 1 when we push it into the queue, not when we pop it from the queue.
                    }
                }
            }
            level++;
        }
    }
};
