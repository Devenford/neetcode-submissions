class Solution {
    int dfs(int i, vector<int>& nums, int sum, int targetSum, vector<vector<int>> &cache) {
        if (i == nums.size()) {
            return 0;
        }
        if (sum == targetSum) {
            return 1;
        }
        if (sum > targetSum) {
            return 0;
        }
        if (cache[i][sum] != -1) {
            return cache[i][sum];
        }

        cache[i][sum] = max(dfs(i+1, nums, sum, targetSum, cache), dfs(i+1, nums, sum + nums[i], targetSum, cache));
        // max(0, 1) = 1, max(0, 0) = 0, max(1, 1) = 1,  it's like an OR operator ||
        return cache[i][sum]; 
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) {
            totalSum += n;
        }
        if (totalSum % 2 == 1) { // array can't be divided into 2 subsets with the same sum
            return false;
        }
        int targetSum = totalSum/2; // each subset must have this sum, i.e. this is the capacity in knapsack
        vector<vector<int>> cache(nums.size(), vector<int> (targetSum+1,  -1));
        // -1 = not computed yet, 0 = false, 1 = true
        return dfs(0, nums, 0, targetSum, cache) == 1 ? true : false;
    }
};
