// Sliding Window Kadane's Algo.
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = 0, maxL = 0, maxR = 0, L = 0;
        for (int R=0; R<nums.size(); R++) {
            if (currSum < 0) {
                currSum = 0;
                L = R;
            }
            currSum += nums[R];
            if (currSum > maxSum) {
                maxSum = currSum;
                maxL = L;
                maxR = R;
            }
        }
        // return vector<int>{maxL, maxR};
        return maxSum;
    }
};
