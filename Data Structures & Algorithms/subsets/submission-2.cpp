#include <vector>

class Solution {
   public:
    void recurse(int i, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subs) {
        if (i == nums.size()) {
            subs.push_back(subset);
            return;
        }

        recurse(i + 1, nums, subset, subs);
        subset.push_back(nums[i]);
        recurse(i + 1, nums, subset, subs);

        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> temp;
        recurse(0, nums, temp, subs);
        return subs;
    }
};
