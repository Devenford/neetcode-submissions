#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;


        int curr1 = 0, curr2 = 0;
        while(curr1 + curr2 < (n - 1)/2) {
            if (curr1 < n1 && curr2 < n2) {
                nums1[curr1] <= nums2[curr2] ? curr1++ : curr2++;
            }
            else if (curr1 < n1) {
                curr1++;
            }
            else {
                curr2++;
            }
        }

        if (n%2 == 0) {
            if (curr1 < n1 && curr2 < n2) {
                if (curr1 + 1 < n1 && nums1[curr1 + 1] <= nums2[curr2]) {
                    return ((double) nums1[curr1] + nums1[curr1 + 1])/2;
                }
                else if (curr2 + 1 < n2  && nums2[curr2 + 1] <= nums1[curr1]) {
                    return ((double) nums2[curr2] + nums2[curr2 + 1])/2;
                }
                else {
                    return ((double) nums1[curr1] + nums2[curr2])/2;
                }
            }
            else if (curr1 < n1) {
                return ((double) nums1[curr1] + nums1[curr1 + 1])/2;
            }
            else {
                return ((double) nums2[curr2] + nums2[curr2 + 1])/2;
            }
        }
        else {
            if (curr1 < n1 && curr2 < n2) {
                return min(nums1[curr1], nums2[curr2]);
            }
            else if (curr1 < n1) {
                return nums1[curr1];
            }
            else {
                return nums2[curr2];
            }
        }
    }
};
