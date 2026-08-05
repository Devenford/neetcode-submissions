// bottom-up dp approach
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = weight.size(), M = capacity;
        vector<vector<int>> dp(N, vector<int> (M+1, 0));

        // initialize first col
        for (int i=0; i<N; i++) {
            dp[i][0] = 0;
        }
        //initialize first row
        for (int c = 0; c <= M; c++) { // c = curr capacity
            if (weight[0] <= c) {
                dp[0][c] = profit[0];
            }
        }

        for(int i = 1; i<N ; i++) {
            for(int c = 1; c <= M; c++) {
                int maxProfit = dp[i-1][c];  // skipping it

                if (weight[i] <= c) {
                    maxProfit = max(maxProfit, profit[i] + dp[i-1][c-weight[i]]); // including it
                }
                dp[i][c] = maxProfit;
            }
        }

        return dp[N-1][M];
    }
};
