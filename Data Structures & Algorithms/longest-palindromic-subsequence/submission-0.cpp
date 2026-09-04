// top-down (memoization)

#include<string>
#include<algorithm>
using namespace std;

class Solution {
    int dfs(int i, int j, string &s, string &r, vector<vector<int>> &cache) {
        if (i >= s.size() || j >= r.size()) {
            return 0;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        
        if (s[i] == r[j]) {
            cache[i][j] = 1 + dfs(i+1, j+1, s, r, cache);
        }
        else {
            cache[i][j] = max(dfs(i+1, j, s, r, cache), dfs(i, j+1, s, r, cache));
        }

        return cache[i][j];
    }

public:
    int longestPalindromeSubseq(string s) {
        string r = s; // r = reverse of string s
        reverse(r.begin(), r.end());
        vector<vector<int>> cache(s.size(), vector<int> (r.size(), -1));
        return dfs(0, 0, s, r, cache);
    }
};