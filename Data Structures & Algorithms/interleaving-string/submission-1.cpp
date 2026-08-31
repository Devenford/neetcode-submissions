// memoization

#include<string>
#include<vector>
using namespace std;

class Solution {
    bool dfs(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &cache) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        bool result = false;
        // Try taking the next character from s1
        if (i < s1.size() && s1[i] == s3[k]) {
            if (dfs(i+1, j, k+1, s1, s2, s3, cache)) {
                result = true;
            }
        }
        // Try taking the next character from s2
        if (j < s2.size() && s2[j] == s3[k]) {
            if (dfs(i, j+1, k+1, s1, s2, s3, cache)) {
                result = true;
            }
        }
        
        cache[i][j] = result;
        return result;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }
        vector<vector<int>> cache(n+1, vector<int> (m+1, -1));
        // +1 to include states where all characters of s1 or s2 have been consumed
        return dfs(0, 0, 0, s1, s2, s3, cache);
    }
};

