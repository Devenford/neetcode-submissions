#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertAt = 0;

        for (int num : nums) {
            if (insertAt < 2 || num != nums[insertAt-2]) {
                nums[insertAt++] = num;
            }
        }
        
        return insertAt;
    }
};