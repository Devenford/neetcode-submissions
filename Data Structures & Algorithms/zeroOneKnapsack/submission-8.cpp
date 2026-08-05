// optimized space comp. bottom-up dp approach
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int N = weight.size(), M = capacity;
        vector<int> prevRow(M+1, 0); // previous row

        // initialize first row
        for (int c=0; c <= M; c++) { // capacity
            if (weight[0] <= c) {
                prevRow[c] = profit[0];
            }
        }

        for (int i = 1; i < N; i++) {
            vector<int> currRow (M+1, 0);
            for (int c = 1; c <= M ; c++) {
                int maxProfit = prevRow[c];

                if (weight[i] <= c) {
                    maxProfit = max(maxProfit, profit[i] + prevRow[c-weight[i]]);
                }
                currRow[c] = maxProfit;
            }
            prevRow = currRow;
        }

        return prevRow[M];
    }
};
