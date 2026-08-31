// bottom-up dp

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n+m != s3.size()) {
            return false;
        }
        vector<bool> prev(n+1, false);
        prev[m] = true;
        for(int j=m-1; j>=0; --j) {
            if (s2[j] == s3[n+j]) {
                prev[j] = true; 
            }
        }

        for(int i=n-1; i>=0; --i) {
            vector<bool> dp(n+1, false);
            if (s1[i] == s3[i+m]) {
                dp[m] = prev[m];
            }
            for(int j = m-1; j>=0; --j) {
                if (s1[i] == s3[i+j]) {
                    dp[j] = prev[j];
                }
                if (s2[j] == s3[i+j]) {
                    dp[j] = dp[j+1];
                }
            }
            prev = dp;
        }

        return prev[0];
    }
};
