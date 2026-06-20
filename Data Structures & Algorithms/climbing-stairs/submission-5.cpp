class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) {
            return n;
        }
        int dp[] = {1, 2};
        for (int i=3; i<=n; i++) {
            int temp = dp[1];
            dp[1] = dp[1] + dp[0];
            dp[0] = temp;
        }
        return dp[1];
    }
};
