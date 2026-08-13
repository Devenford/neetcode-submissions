// memoization

#include<vector>
using namespace std;

class Solution {
    int dfs(int i, int amount, vector<int> &coins, int sum, vector<vector<int>> &cache) {
        if (sum > amount) {
            return 0;
        }
        if (sum == amount) {
            return 1;
        }
        if (cache[i][sum] != -1) {
            return cache[i][sum];
        }

        int count = 0;
        for(int j=i; j<coins.size(); j++) {
            count += dfs(j, amount, coins, sum + coins[j], cache);
        }

        cache[i][sum] = count;
        return count;
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> cache(coins.size(), vector<int> (amount, -1));
        return dfs(0, amount, coins, 0, cache);
    }
};