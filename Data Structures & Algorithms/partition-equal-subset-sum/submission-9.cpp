class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) {
            totalSum += n;
        }
        // The two subsets must have equal sums, so the total sum must be even.
        if (totalSum % 2 == 1) {
            return false;
        }
        int N = nums.size(), M = totalSum / 2;
        vector<vector<bool>> dp(N, vector<bool> (M+1, false));
        // dp[i][c] = whether we can make sum c using nums[0..i].

        // Sum 0 is always possible by choosing no elements.
        for(int i = 0; i<N; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i < N; i++) {
            for(int c = 1; c <= M; c++) {
                // Don't include nums[i]. 
                // If we could make c using previous elements dp[i-1][c], we can still make c without nums[i].
                dp[i][c] = dp[i-1][c];

                // Include nums[i].
                // We need the previous elements to make the remaining sum c - nums[i], thus dp[i-1][c-nums[i]]
                if (nums[i] <= c) {
                    dp[i][c] = dp[i][c] || dp[i-1][c-nums[i]];
                }
            }
        }

        // If we can make half of the total sum, the remaining elements also sum to M.
        return dp[N-1][M];
    }
};
