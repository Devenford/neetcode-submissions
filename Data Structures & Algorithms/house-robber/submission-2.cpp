#include<algorithm>

class Solution {

public:
    int rob(vector<int>& nums) {
        int rob1=0, rob2=0;
        // rob1 = best up to house i-2
        // rob2 = best up to house i-1
        // rob1, rob2, house i  -> order

        for(int num: nums) {
            int temp = max(rob2, rob1+num);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
