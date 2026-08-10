class Solution {
    int dfs(int i, vector<int> &profit, vector<int> &weight, int capacity, vector<vector<int>> &cache) {
        if (i == profit.size()) {
            return 0;
        }
        if (cache[i][capacity] != -1) {
            return cache[i][capacity];
        }

        // exclude item
        int maxProfit = dfs(i+1, profit, weight, capacity, cache);
        // include item if resultant capacity is >= 0
        int newCap = capacity-weight[i];
        if (newCap >= 0) {
            maxProfit = max(maxProfit, profit[i] + dfs(i, profit, weight, newCap, cache));

        }

        cache[i][capacity] = maxProfit;
        return maxProfit;
    }

public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = profit.size(), M = capacity;
        vector<vector<int>> cache(N, vector<int> (M+1, -1));
        return dfs(0, profit, weight, capacity, cache);
    }
};
