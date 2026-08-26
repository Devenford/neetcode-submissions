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
        // Base case, before the loop starts (i == n, empty suffix of s): there's exactly 1 way to match the empty suffix of t (t[m:]) — pick nothing.


        for(int i=n-1; i>=0; i--) {
            vector<int> dp(m+1, 0);
            dp[m] = 1;
            // Same base case, re-asserted for every row: matching the empty suffix of t (t[m:]) using s[i:] is always possible in exactly 1 way (pick nothing), regardless of i.
            for(int j=m-1; j>=0; j--) {
                // exclude char
                dp[j] = prev[j];
                // Exclude s[i]: ways to match t[j:] using s[i+1:] (one fewer char of s, same target suffix). prev is the row for i+1, so prev[j] = ways to match t[j:] without using s[i] at all.
                if (s[i] == t[j]) { // include char
                    dp[j] += prev[j+1];
                    // Include s[i] as a match for t[j]: use s[i] to cover t[j], then match the rest of the target (t[j+1:]) using s[i+1:] onward — that count is prev[j+1].
                }
            }
            prev = dp;
        }

        return prev[0];
    }
};
