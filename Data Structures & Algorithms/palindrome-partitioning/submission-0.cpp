#include<string>
#include<vector>
using namespace std;

class Solution {
    bool checkPalindrome(string &s) {
        for(int i=0; i<s.size()/2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int i, string s, string curr, vector<string> &currSol, vector<vector<string>> &sol) {
        if (i == s.size()) {
            if (curr.empty()) {
                sol.push_back(currSol);
            }
            return;
        }

        curr.push_back(s[i]);
        if (checkPalindrome(curr)) {
            currSol.push_back(curr);
            dfs(i+1, s, "", currSol, sol); // create a partition, start a new string
            currSol.pop_back();
        }
        dfs(i+1, s, curr, currSol, sol); // add to current string
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> currSol;
        dfs(0, s, "", currSol, sol);
        return sol;
    }
};
