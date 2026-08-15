// using memo
#include<vector>
using namespace std;

class Solution {
    int dfs(int i, int j, string &text1, string &text2, vector<vector<int>> &cache) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        if (text1[i] == text2[j]) {
            cache[i][j] = 1 + dfs(i+1, j+1, text1, text2, cache);
        }
        else {
            cache[i][j] = max(dfs(i+1, j, text1, text2, cache), dfs(i, j+1, text1, text2, cache));
        }

        return cache[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size(), vector<int> (text2.size(), -1));
        return dfs(0, 0, text1, text2, cache);
    }
};
