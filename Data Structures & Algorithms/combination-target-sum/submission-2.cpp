#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void getCombos(int i, int sum, vector<int> &currComb, vector<int> &nums, vector<vector<int>> &sol, int target) {
        if (sum == target) {
            sol.push_back(currComb);
            return;
        }
        if (sum > target) {
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            currComb.push_back(nums[j]);
            sum += nums[j];
            getCombos(j, sum, currComb, nums, sol, target);
            sum -= nums[j];
            currComb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> currComb;
        sort(nums.begin(), nums.end());
        getCombos(0, 0, currComb, nums, sol, target);
        return sol;
    }
};
