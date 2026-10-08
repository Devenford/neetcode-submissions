#include<climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int L = 0, R = nums.size() - 1, minNum = INT_MAX;

        while (L <= R) {
            int mid = (L + R)/2;

            if (nums[mid] <= nums[R] && nums[mid] <= nums[L]){
                minNum = min(minNum, nums[mid]);
                R = mid -1;
            }
            else if (nums[mid] <= nums[R]) {
                R = mid - 1;
            }
            else if (nums[mid] >= nums[L]){
                L = mid + 1;
            }
            else {
                return nums[mid];
            }
        }

        return minNum;
    }
};
