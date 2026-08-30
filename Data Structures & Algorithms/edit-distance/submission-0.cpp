#include<string>
#include<algorithm>
using namespace std;

class Solution {
    int dfs(int i, int j, string &word1, string &word2, vector<vector<int>> &cache) {
        if (i >= word1.size()) {
            return word2.size() - j;
        }
        if (j >= word2.size()) {
            return word1.size() - i;
        }
        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        int numOps; // number of operations
        if (word1[i] == word2[j]) {
            numOps = dfs(i+1, j+1, word1, word2, cache);
        }
        else {
            numOps = 1 + min({dfs(i, j+1, word1, word2, cache), dfs(i+1, j, word1, word2, cache), dfs(i+1, j+1, word1, word2, cache)});
            // min(insert, delete, replace)
        }

        cache[i][j] = numOps;
        return numOps;
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> cache(word1.size(), vector<int> (word2.size(), -1));
        return dfs(0, 0, word1, word2, cache);
    }
};
