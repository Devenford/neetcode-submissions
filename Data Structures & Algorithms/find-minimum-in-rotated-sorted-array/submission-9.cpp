class Solution {
public:
    int findMin(vector<int> &nums) {
        int L = 0, R = nums.size() - 1, minNum = nums[0];

        while (L <= R) {
            if (nums[L] < nums[R]) { // already sorted
                minNum = min(minNum, nums[L]);
                break;
            }

            int mid = (L+R)/2;
            minNum = min(minNum, nums[mid]);

            if (nums[mid] < nums[L]) {
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }

        return minNum;
    }
};
