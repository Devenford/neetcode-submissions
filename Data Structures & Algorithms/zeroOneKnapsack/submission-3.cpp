// top-down memoization approach
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int memoize(int i, vector<int>& profit, vector<int>& weight, int capacity, vector<vector<int>> &cache) {
        if (i == weight.size()) {
            return 0;
        }
        if (cache[i][capacity] != -1) { // already computed
            return cache[i][capacity];
        }

        // skip it
        int maxProfit = memoize(i+1, profit, weight, capacity, cache);

        // include it
        int newCap = capacity - weight[i];
        if (newCap >= 0) {
            int p = profit[i] + memoize(i+1, profit, weight, newCap, cache);
            maxProfit = max(maxProfit, p);
        }

        cache[i][capacity] = maxProfit;
        return maxProfit;
    }

public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = weight.size(), M = capacity;
        vector<vector<int>> cache(N, vector<int> (M+1, -1));
        return memoize(0, profit, weight, capacity, cache);
    }
};
