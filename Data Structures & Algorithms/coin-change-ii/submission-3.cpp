// dp (bottom-up)

#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1, 0);
        
        for(int c=0; c<=amount; c++) {
            if (c % coins[0] == 0) {
                prev[c] = 1;
            }
        }

        for(int i=1; i<coins.size(); i++) {
            vector<int> dp(amount+1, 0);
            for(int c=0; c<=amount; c++) {
                dp[c] = prev[c]; // exclude it

                int remainingAmount = c - coins[i];
                if (remainingAmount >= 0) {
                    dp[c] = dp[c] + dp[remainingAmount];
                    // dp[remainingAmount] since it's unbounded knapsack, i.e. you can choose the same coin again while you're still at this coin i
                }
            }

            prev = dp;
        }

        return prev[amount];
    }
};
