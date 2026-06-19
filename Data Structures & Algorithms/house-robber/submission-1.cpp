#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int dp(int i, vector<int> &nums, vector<int> &cache) {
        if (i>=nums.size()) {
            return 0;
        }
        if (cache[i] != -1) {
            return cache[i];
        }

        cache[i] = max(dp(i+1, nums, cache), nums[i] + dp(i+2, nums, cache));
        return cache[i];
    }

public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return dp(0, nums, cache);
    }
};
