// dp bottom-up + Tracing

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int j=m-1; j>=0; j--) {
            dp[n][j] = m-j;
        }
        for (int i=n-1; i>=0; i--) {
            dp[i][m] = n-i;
        }
        
        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = min(1 + dp[i+1][j], 1 + dp[i][j+1]);
                }
            }
        }

        string result;
        int i=0, j = 0;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                result.push_back(str1[i]);
                i++;
                j++;
            }
            else if (dp[i+1][j] < dp[i][j+1]) {
                result.push_back(str1[i]);
                i++;
            }
            else {
                result.push_back(str2[j]);
                j++;
            }
        } 

        while (i<n) {
            result.push_back(str1[i]);
            i++;
        }

        while (j<m) {
            result.push_back(str2[j]);
            j++;
        }

        return result;
    }
};