#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

    void getCombos(int i, string& currStr, string& digits, vector<string>& sol) {
        if (i == digits.size()) {
            sol.push_back(currStr);
            return;
        }

        for (char c : digitToChar[digits[i] - '0']) {
            currStr.push_back(c);
            getCombos(i + 1, currStr, digits, sol);
            currStr.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if (digits.empty()) {
            return sol;
        }
        string currStr;
        getCombos(0, currStr, digits, sol);
        return sol;
    }
};
