#include<algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int L = 0, R = nums.size()-1;
        while (L < R) {
            int mid = (L+R)/2;
            
            if (nums[mid] < nums[R]) { // if nums[mid] < nums[R], then the array[mid to R] is sorted, and the min element lies in the left half
                R = mid;
            }
            else { // if nums[mid] > nums[L], then the array[L to mid] (left half) is sorted, and the min element lies in the right half
                L = mid + 1;
            }
        }
        return nums[L];
    }
};
