#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 1, R = 1, count = 1; // insert at L, curr = R

        while(R<nums.size()) {
            if (nums[R] != nums[R-1]) {
                count = 1;
                nums[L++] = nums[R];
            }
            else if (count < 2) {
                count++;
                nums[L++] = nums[R];
            }
            else {
                count++;
            }

            R++;
        }
        
        return L;
    }
};