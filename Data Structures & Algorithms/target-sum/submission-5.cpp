#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (abs(target) > sum) { // target can never be obtained
            return 0;
        }
        int N = nums.size(), offset = sum, M = 2 * sum;
        // 2*sum to account for range -sum to sum
        vector<vector<int>> dp(N, vector<int>(M+1, 0)); 

        dp[0][offset + nums[0]] += 1;
        dp[0][offset - nums[0]] += 1;
        
        for(int i=1; i<N; i++) {
            for(int s = 0; s<=M ; s++) { // s = sum
                if (s+nums[i] <= M) {
                    dp[i][s] += dp[i-1][s+nums[i]];
                }
                if (s-nums[i] >=0) {
                    dp[i][s] += dp[i-1][s-nums[i]];
                }
            }
        }
        return dp[N-1][offset + target];
    }
};
