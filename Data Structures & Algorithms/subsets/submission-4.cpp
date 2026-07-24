#include<vector>


class Solution {
public:
    void getSubsets(int i, vector<int> &currSet, vector<int> &nums, vector<vector<int>> &sol) {
        if (i == nums.size()) {
            sol.push_back(currSet);
            return;
        }

        currSet.push_back(nums[i]);
        getSubsets(i+1, currSet, nums, sol);
        currSet.pop_back();

        getSubsets(i+1, currSet, nums, sol);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> currSet;
        getSubsets(0, currSet, nums, sol);
        return sol;
    }
};
