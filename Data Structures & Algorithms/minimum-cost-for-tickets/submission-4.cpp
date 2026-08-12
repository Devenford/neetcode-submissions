// memoization (top-down) solution
// Unbounded knapsack: at each state, we can repeatedly choose any pass type.
// The pass duration determines how far we advance to the next uncovered day.

#include<vector>
using namespace std;

class Solution { // 1D -DP
    int dfs(int i, vector<int> &days, vector<int> &costs, vector<int> &pass, vector<int> &dp) {
        // i = index in days array
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int minCost = INT_MAX;
        for(int j=0; j<pass.size(); j++) { // check each pass
            int nextDay = days[i] + pass[j];
            int k = i;
            while (k < days.size() && days[k] < nextDay) { 
                // k < days.size() ensures k doesn't go out-of-bounds and accesses an invalid index with days[k]
                k++;
            }
            minCost = min(minCost, costs[j] + dfs(k, days, costs, pass, dp));
        }

        dp[i] = minCost;
        return minCost;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> pass = {1, 7, 30};
        vector<int> dp(days.size(), -1);
        return dfs(0, days, costs, pass, dp);
    }
};