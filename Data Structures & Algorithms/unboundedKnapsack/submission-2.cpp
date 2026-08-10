class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = profit.size(), M = capacity;
        vector<int> prev(M+1, 0); // previous row

        for(int i=0; i<N; i++) {
            vector<int> dp(M+1, 0); // curr row
            for(int j=0; j<=M; j++) { // j = c = capacity
                //exclude item
                dp[j] = prev[j];

                //include item
                int newCap = j - weight[i];
                if (newCap >= 0) {
                    dp[j] = max(dp[j], profit[i] + dp[newCap]);
                }
            }

            prev = dp;
        }

        return prev[M];
    }
};

