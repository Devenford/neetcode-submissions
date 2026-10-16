#include<string>
#include<vector>
using namespace std;

class Solution {
    bool checkPalindrome(string s) {
        for(int i = 0; i<s.size()/2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int i, int j, string &s, vector<string> &currSol, vector<vector<string>> &sol) { // i to j is the current substring
        if (j == s.size()) {
            if (i == j) {
                sol.push_back(currSol);
            }
            return;
        }

        if (checkPalindrome(s.substr(i, j - i + 1))) {
            // create a partition and start a new string
            currSol.push_back(s.substr(i, j - i + 1));
            dfs(j + 1, j + 1, s, currSol, sol);
            currSol.pop_back();
        }
        dfs(i, j + 1, s, currSol, sol); // continue without partitioning
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> currSol;
        dfs(0, 0, s, currSol, sol);
        return sol;
    }
};
