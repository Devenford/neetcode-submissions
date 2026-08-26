// dp solution
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m+1, 0);
        prev[0] = 1; // empty prefix of t matches empty prefix of s in exactly 1 way

        for(int i=0; i<n; i++) {
            vector<int> dp(m+1, 0);
            dp[0] = 1;
            for(int j=1; j<=m; j++) {
                // exclude char
                dp[j] = prev[j];
                if (s[i] == t[j-1]) {
                    dp[j] += prev[j-1];
                }
            }
            prev = dp;
        }

        return prev[m];
    }
};
