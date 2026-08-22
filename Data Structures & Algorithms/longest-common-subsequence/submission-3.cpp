// using dp (2 vector memory)
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1, 0);

        for(int i=0; i<n; i++) {
            vector<int> dp(m+1, 0);
            for(int j=0; j<m; j++) {
                if (text1[i] == text2[j]) {
                    dp[j+1] = 1 + prev[j];
                }
                else {
                    dp[j+1] = max(dp[j], prev[j+1]);
                }
            }
            prev = dp;
        }

        return prev[m];
    }
};
