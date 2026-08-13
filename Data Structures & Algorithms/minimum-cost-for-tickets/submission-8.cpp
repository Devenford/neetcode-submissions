// dp (bottom-up) solution
// Unbounded knapsack: at each state, we can repeatedly choose any pass type.
// The pass duration determines how far we advance to the next uncovered day.

#include<vector>
#include<climits>
#include<cfloat>
#include<algorithm>
using namespace std;

class Solution { // 1D -DP
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> pass = {1, 7, 30};
        vector<int> dp(days.size()+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=days.size(); i++) {
            dp[i] = INT_MAX;

            for(int j=0; j<pass.size(); j++) {
                int k = i;
                while (k > 0 && days[k-1] > days[i-1] - pass[j]) {
                    k--;
                }
                dp[i] = min(dp[i], costs[j] + dp[k]);
            }
        }

        return dp[days.size()];
    }
};