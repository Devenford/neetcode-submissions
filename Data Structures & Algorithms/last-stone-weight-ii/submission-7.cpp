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
        vector<bool> prev(M+1, false);
        // dp[i][c] = can I make a subset using stones 0..i that sums to exactly c?
        // bool since we either include or exclude a stone

        // initialize first row
        if (stones[0] <= M) {
            prev[stones[0]] = true;
        }
        // initialize first column
        prev[0] = true; // we can meet sum 0 by not choosing the stone

        for(int i = 1; i < N; i++) {
            vector<bool> dp(M+1, false);
            // initialize first column
            dp[0] = true; // we can meet sum 0 by not choosing the stone

            for(int c = 1; c <= M; c++) {
                   dp[c] = prev[c]; // exclude current stone
                   if (stones[i] <= c) { // include current stone
                    dp[c] = dp[c] || prev[c-stones[i]];
                   }
            }
            prev = dp;
        }

        int maxCap = M;
        while(maxCap > 0) {
            if (prev[maxCap]) { // if true
                break;
            }
            maxCap--;
        }
        
        return sum - (2*maxCap);
    }
};