#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int fresh = 0; // number of fresh fruits
        queue<pair<int, int>> q;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                }
                else if (grid[i][j]) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        if (fresh==0) {
            return minutes;
        }
        while(q.size()) {
            if (fresh==0) {
                return minutes;
            }
            int qlength = q.size();
            for(int i=0; i<qlength; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                int r = curr.first, c = curr.second;
                
                vector<vector<int>> neighbors = {
                    {r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}
                };
                for(int j=0; j<4; j++) {
                    int newR = neighbors[j][0], newC = neighbors[j][1];
                    if(newR<0 || newC<0 || newR==rows || newC==cols || grid[newR][newC]==2 || grid[newR][newC]==0) {
                        continue;
                    }

                    q.push({newR, newC});
                    grid[newR][newC] = 2;
                    fresh--;
                }
            }
            minutes++;
        }

        return -1;
    }
};
