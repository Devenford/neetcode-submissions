#include<climits>
#include<algorithm>
using namespace std;

class Solution {
// We're using binary search to find the correct left partitions.
// Ex: list 1 = [1, 7, 8, 9]
// list 2 = [1, 2, 3]
// left partition of list 1 = [1] and the left partition of list 2 = [1, 2]
// combined list = [1, 1, 2, 3, 7, 8, 9], total left partition = [1, 1, 2], the total right partition = [7, 8, 9], median = 3

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        int half = n/2; // half the total number of elements
        int L = 0, R = n1;
        // L = minimum number of elements we can take from nums1 for the left partition
        // R = maximum number of elements we can take from nums1 for the left partition

        while (L <= R) {
            int i = (L + R)/2;
            int j = half - i;
            // i = number of elements taken from A (the shorter array) for the left half
            // j = number of elements taken from B for the left half, so i + j == half
            // lefti = last number in left partition of array i
            // righti = one past the last number in left partition of array i
            int left1 = i == 0 ? INT_MIN : nums1[i - 1];
            int right1 = i >= n1 ? INT_MAX : nums1[i];
            int left2 = j == 0 ? INT_MIN : nums2[j - 1];
            int right2 = j >= n2 ? INT_MAX : nums2[j];
            // left partition of list1 = 0 to mid1
            // left partition of list2 = 0 to mid2

            if (left1 <= right2 && left2 <= right1) {
                if (n%2 == 0) { // even number of elements
                    return ((double) max(left1, left2) + min(right1, right2))/2;
                }
                else { // odd number of elements
                    return min(right1, right2);
                }
            }
            else if (left1 <= right2) {
                L = i + 1;
            }
            else {
                R = i - 1;
            }
        }

        return -1;
    }
};
