#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
    int dfs(int i, vector<int>& days, vector<int>& costs, vector<int> &pass, vector<int> &cache) {
        if (i >= days.size()) {
            return 0;
        }
        if (cache[i] != -1) {
            return cache[i];
        }

        int minCost = INT_MAX;
        for(int j=0; j<costs.size(); j++) {
            int k = i, nextDay = days[i] + pass[j];
            while(k < days.size() && days[k] < nextDay) {
                k++;
            }
            minCost = min(minCost, costs[j] + dfs(k, days, costs, pass, cache));
        }

        cache[i] = minCost;
        return minCost;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> pass = {1, 7, 30};
        vector<int> cache(days.size(), -1);
        return dfs(0, days, costs, pass, cache);
    }
};