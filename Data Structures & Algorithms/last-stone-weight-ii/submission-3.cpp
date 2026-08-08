#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int s : stones) {
            sum += s;
        }
        int N = stones.size(), M = sum/2; 
        vector<vector<bool>> dp(N, vector<bool> (M+1, false));
        // dp[i][c] = can I make a subset using stones 0..i that sums to exactly c?
        // bool since we either include or exclude a stone

        // initialize first row
        if (stones[0] <= M) {
            dp[0][stones[0]] = true;
        }
        // initialize first column
        for(int i=0; i<N; i++) {
            dp[i][0] = true; // we can meet sum 0 by not choosing the stone
        }

        for(int i = 1; i < N; i++) {
            for(int c = 1; c <= M; c++) {
                   dp[i][c] = dp[i-1][c]; // exclude current stone
                   if (stones[i] <= c) { // include current stone
                    dp[i][c] = dp[i][c] || dp[i-1][c-stones[i]];
                   }
            }
        }

        int maxCap = M;
        while(maxCap > 0) {
            if (dp[N-1][maxCap]) { // if true
                break;
            }
            maxCap--;
        }
        
        // if x = sum/2 is one group's sum and other group's sum is (sum-x), then the difference between these groups is (sum-x) - x = sum - 2x. We need to minimize this difference. 
        return sum - (2*maxCap);
    }
};