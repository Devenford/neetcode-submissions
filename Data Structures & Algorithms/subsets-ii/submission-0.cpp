#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void getSubsets(int i, vector<int> &currSub, vector<int> &nums, vector<vector<int>> &sol) {
        if (i == nums.size()) {
            sol.push_back(currSub);
            return;
        }

        currSub.push_back(nums[i]);
        getSubsets(i+1, currSub, nums, sol);
        currSub.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
           i++; 
        }
        getSubsets(i+1, currSub, nums, sol);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> currSub;
        sort(nums.begin(), nums.end());
        getSubsets(0, currSub, nums, sol);
        return sol;    
    }
};
