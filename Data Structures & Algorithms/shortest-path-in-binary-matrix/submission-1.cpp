#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) {
            return -1;
        }
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visit(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visit[0][0] = 1;
        int length = 1;

        while(q.size()) {
            int qlength = q.size();

            for(int i=0; i<qlength; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                int r = curr.first, c = curr.second;
                if(r==rows-1 && c==cols-1) {
                    return length;
                }

                vector<vector<int>> neighbors = {
                    {r-1, c-1}, {r-1, c}, {r-1, c+1},
                    {r, c-1}, {r, c+1},
                    {r+1, c-1}, {r+1, c}, {r+1, c+1}
                };
                for(int j=0; j<8; j++) {
                    int newR = neighbors[j][0], newC = neighbors[j][1];
                    if(newR<0 || newC<0 || newR==rows || newC==cols || grid[newR][newC] || visit[newR][newC]) {
                        continue;
                    }

                    q.push({newR, newC});
                    visit[newR][newC] = 1;
                }
            }
            length++;
        }
        return -1;
    }
};