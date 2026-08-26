// memo solution
#include<string>
using namespace std;

class Solution {
    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &cache) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        // exclude curr character in s
        int count = dfs(i+1, j, s, t, cache);
        if (s[i] == t[j]) {
            // include curr character in s
            count += dfs(i+1, j+1, s, t, cache);
        }

        cache[i][j] = count;
        return count;
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> cache(s.size(), vector<int> (t.size(), -1));
        return dfs(0, 0, s, t, cache);
    }
};
