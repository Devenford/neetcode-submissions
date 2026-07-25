#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<char, vector<char>> digitLettersMap = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, 
        {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, 
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
    };

    void getCombos(int i, string &currStr, string &digits, vector<string> &sol) {
        if (i == digits.size()) {
            sol.push_back(currStr);
            return;
        }

        for (char c : digitLettersMap[digits[i]]) {
            currStr.push_back(c);
            getCombos(i+1, currStr, digits, sol);
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
