#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window; // hash set
        int L = 0;

        for(int R=0; R < nums.size(); R++) {
            if (R-L > k) {
                window.erase(nums[L++]);
            }
            if (window.count(nums[R])>0) {
                return true;
            }
            window.insert(nums[R]);
        }
        return false;
    }
};