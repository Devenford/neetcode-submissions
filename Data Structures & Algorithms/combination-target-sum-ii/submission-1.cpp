#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    void dfs(int i, int sum, int target, vector<int> &combo, vector<int> &candidates, vector<vector<int>> &sol) {
        if (sum == target) {
            sol.push_back(combo);
            return;
        }
        if (i >= candidates.size() || sum > target) {
            return;
        }


        sum += candidates[i];
        combo.push_back(candidates[i]);
        dfs(i+1, sum, target, combo, candidates, sol);
        combo.pop_back();
        sum -= candidates[i];

        while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(i+1, sum, target, combo, candidates, sol);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> sol;
        vector<int> combo;
        dfs(0, 0, target, combo, candidates, sol);
        return sol;
    }
};
