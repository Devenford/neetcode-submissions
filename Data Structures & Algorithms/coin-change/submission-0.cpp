#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size(), M = amount;
        int maxNum = amount + 1; // since if a solution exists, every coin is worth at least 1, so you can never need more than amount coins.
        vector<int> prev(M+1, maxNum);
        vector<int> curr(M+1, maxNum);

        prev[0] = 0;
        curr[0] = 0;

        for(int i=0; i<N; i++) {
            for(int j=1; j<=M; j++) {
                curr[j] = prev[j];
                int newCap = j - coins[i];
                if (newCap >= 0) {
                    curr[j] = min(curr[j], 1 + curr[newCap]);
                }
            }
            prev = curr;
        }

        return prev[M] == maxNum ? -1 : prev[M];
    }
};
