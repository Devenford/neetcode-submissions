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
        // only 2 rows are required
        vector<bool> prev(M + 1, false);
        prev[0] = true;

        if (nums[0] <= M) {
            prev[nums[0]] = true;
        }
        
        for (int i = 1; i < N; i++) {
            vector<bool> dp(M + 1, false);
            for (int c = 1; c <= M; c++) {
                dp[c] = prev[c];
                if (nums[i] <= c) {
                    dp[c] = dp[c] || prev[c - nums[i]];
                }
            }
            prev = dp;
        }
        return prev[M];
    }
};