#include <vector>
#include <algorithm>

class Solution {
public:
    bool recurse(vector<int> &nums, int target, int sum, int start, vector<int> &combo, vector<vector<int>> &allcombos) {
        if(sum > target) {
            return false;  // on failure don't continue
        }
        if (sum == target) {
            allcombos.push_back(combo);
            return false;   // on success don't continue
        }

        // start is the starting index
        for(int i=start; i<nums.size(); i++) {
            combo.push_back(nums[i]);
            if(!recurse(nums, target, sum + nums[i], i, combo, allcombos)) {
                combo.pop_back();
                break;
            }
            combo.pop_back();
        }


        return true;  // continue if sum is less than target
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> allcombos;
        vector<int> combo;
        sort(nums.begin(), nums.end());
        recurse(nums, target, 0, 0, combo, allcombos);
        return allcombos;
    }
};
