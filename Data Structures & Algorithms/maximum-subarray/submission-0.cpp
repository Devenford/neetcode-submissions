// Kadane's Algorithm:
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = 0;
        for (int num : nums) {
            currSum += num;
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0);
        }
        return maxSum;
    }
};
