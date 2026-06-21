#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> currRow(cols+1, 0);
        currRow[cols-1] = 1;

        for(int r = rows-1; r>=0; r--) {
            for(int c = cols-1; c>=0; c--) {
                if(obstacleGrid[r][c]) {
                    currRow[c] = 0;
                }
                else {
                    currRow[c] += currRow[c+1];
                }
            }
        }

        return currRow[0];
    }
};