#include<unordered_set>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // undirected, weighted graph
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0}); // {wt, i, j}
        vector<vector<int>> deltas = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int t = 0, rows = grid.size(), cols = grid[0].size();

        while(!minHeap.empty()) {
            vector<int> cell = minHeap.top();
            minHeap.pop();
            t = max(cell[0], t);
            int i = cell[1], j = cell[2];
            if (i == rows-1 && j == cols-1) {
                break;
            }

            for (int k=0; k<4; k++) {
                int r = i + deltas[k][0], c = j + deltas[k][1];
                if (r>=0 && r<rows && c>=0 && c<cols && grid[r][c] != -1) {
                    minHeap.push({max(grid[i][j], grid[r][c]), r, c});
                }
            }

            grid[i][j] = -1;  // -1 = visited
        }

        return t;
    }
};
