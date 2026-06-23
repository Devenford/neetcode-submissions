// Kadane's Algorithm: (simpler)
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = 0;
        for (int num : nums) {
            currSum = max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
