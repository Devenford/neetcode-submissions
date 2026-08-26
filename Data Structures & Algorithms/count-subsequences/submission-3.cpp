// dp solution (backwards)
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m+1, 0);
        prev[m] = 1;

        for(int i=n-1; i>=0; i--) {
            vector<int> dp(m+1, 0);
            dp[m] = 1;
            for(int j=m-1; j>=0; j--) {
                // exclude char
                dp[j] = prev[j];
                if (s[i] == t[j]) { // include char
                    dp[j] += prev[j+1];
                }
            }
            prev = dp;
        }

        return prev[0];
    }
};
