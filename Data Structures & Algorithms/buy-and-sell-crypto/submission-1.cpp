class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0, R = 1, maxP = 0; // max profit

        while(R < prices.size()) {
            if (prices[R] < prices[L]) {
                L = R;
            }
            else {
                maxP = max(maxP, prices[R] - prices[L]);
            }
            R++;
        }
        return maxP;
    }
};
