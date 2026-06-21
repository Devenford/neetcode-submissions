#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> currRow(n+1, 0);
        currRow[n-1] = 1;

        for(int r = m-1 ; r>=0; r--) {
            for(int c = n-1; c >=0; c--) {
                currRow[c] += currRow[c+1];
            }
        }
        return currRow[0];
    }
};
