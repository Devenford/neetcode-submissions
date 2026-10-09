#include<string>
using namespace std;

class Solution {
    void dfs(int open, int closed, int n, string curr, vector<string> &sol) { // open = number of open parentheses, closed = number of closed parentheses
        if (closed > open) {
            return;
        }

        if (curr.size() == 2 * n) {
            if (open == closed) {
                sol.push_back(curr);
            }
            return;
        }

        dfs(open + 1, closed, n, curr + '(', sol);
        dfs(open, closed + 1, n, curr + ')', sol);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        dfs(0, 0, n, "", sol);
        return sol;
    }
};
