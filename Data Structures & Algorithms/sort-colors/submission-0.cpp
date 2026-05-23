class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for(int n : nums) {
            counts[n]++;
        }

        int i=0;
        for(int n=0; n<3; n++) {
            for(int j=0; j<counts[n]; j++) {
                nums[i++] = n;
            }
        }
    }
};