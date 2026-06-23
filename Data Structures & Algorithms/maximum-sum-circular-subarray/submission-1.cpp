#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0], currMaxSum = 0, currMinSum = 0, total = 0;
        
        for (int num: nums) {
            currMaxSum = max(currMaxSum + num, num);
            maxSum = max(maxSum, currMaxSum);
            total += num;
            currMinSum = min(currMinSum + num, num);
            minSum = min(minSum, currMinSum);
        }

        return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};