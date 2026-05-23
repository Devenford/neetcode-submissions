class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int pos = 1;
        int ele = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=ele) {
                nums[pos] = nums[i];
                ele = nums[i];
                pos++;
            }
        }
        nums.resize(pos);
        return pos;
    }
};