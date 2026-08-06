class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) {
            totalSum += n;
        }
        if (totalSum % 2 == 1) {
            return false;
        }
        int N = nums.size(), M = totalSum / 2;
        vector<vector<bool>> dp(N, vector<bool> (M+1, false));

        for(int i = 0; i<N; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i < N; i++) {
            for(int c = 1; c <= M; c++) {
                dp[i][c] = dp[i-1][c];
                if (nums[i] <= c) {
                    dp[i][c] = dp[i][c] || dp[i-1][c-nums[i]];
                }
            }
        }

        return dp[N-1][M];
    }
};
