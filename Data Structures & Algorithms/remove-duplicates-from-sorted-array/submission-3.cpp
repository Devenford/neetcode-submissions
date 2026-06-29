class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 1, insertAt = 1;  // curr = R pointer, prev = L pointer

        while(curr<nums.size()) {
            if (nums[curr]!=nums[curr-1]) {
                nums[insertAt++] = nums[curr];
            }
            curr++;
        }

        nums.resize(insertAt);
        return insertAt;
    }
};