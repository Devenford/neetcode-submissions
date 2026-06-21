#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<int> prevRow(cols, 0);
        prevRow[cols-1] = 1;

        for(int r = rows-1; r>=0; r--) {
            vector<int> currRow(cols, 0);

            if (obstacleGrid[r][cols-1] == 1 || prevRow[cols-1]==0) {
                currRow[cols-1] = 0;
            }
            else {
                currRow[cols-1] = 1;
            }

            for(int c = cols-2; c>=0; c--) {
                if (obstacleGrid[r][c] == 1) {
                    continue;
                }
                currRow[c] = currRow[c+1] + prevRow[c];
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
};