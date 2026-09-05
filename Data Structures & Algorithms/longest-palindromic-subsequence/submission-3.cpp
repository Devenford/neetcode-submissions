// memoization (top-down)

class Solution {
    int dfs(int L, int R, string &s, vector<vector<int>> &cache) {
        if (L < 0 || R >= s.size()) {
            return 0;
        }
        if (cache[L][R] != -1) {
            return cache[L][R];
        }

        if (s[L] == s[R]) {
            if (L == R) {
                cache[L][R] = 1 + dfs(L-1, R+1, s, cache); // same char, at the same position in the string
            }
            else {
                cache[L][R] = 2 + dfs(L-1, R+1, s, cache); // two chars, which are the same but at different positions in the string
            }
        }
        else {
            cache[L][R] = max(dfs(L-1, R, s, cache), dfs(L, R+1, s, cache));
        }

        return cache[L][R];
    }

public:
    int longestPalindromeSubseq(string s) {
        int longest = 0;
        vector<vector<int>> cache(s.size(), vector<int> (s.size(), -1)) ;
        for(int i=0; i<s.size(); i++) {
            longest = max(longest, dfs(i, i, s, cache)); // odd length
            longest = max(longest, dfs(i, i+1, s, cache)); // even length
        }
        return longest;
    }
};