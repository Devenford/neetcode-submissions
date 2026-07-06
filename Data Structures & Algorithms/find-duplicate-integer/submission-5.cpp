
// using a slow and fast pointers
// Ex: If nums[0] = 3, then num[0] is a node that points to nums[3]
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int slow2 = 0;
        while (slow2 != slow) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
};
