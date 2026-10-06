// DP version
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, minB = prices[0]; // minB = min buying price, maxP = max profit

        for(int p : prices) {
            maxP = max(maxP, p - minB);
            minB = min(minB, p);
        }

        return maxP;
    }
};
