// DP version
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, minS = prices[0]; // minS = min selling price, maxP = max profit

        for(int p : prices) {
            maxP = max(maxP, p - minS);
            minS = min(minS, p);
        }

        return maxP;
    }
};
