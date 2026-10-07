// Two pointers
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());

        for (int i=0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; // skip to prevent duplicate triplets
            }

            // since the array is sorted, we can use the two-sum solution:
            int L = i+1, R = nums.size()-1;
            while(L < R) {
                if (L > i+1 && nums[L] == nums[L-1]) {
                    L++;
                    continue;
                }

                if (nums[L] + nums[R] > -nums[i]) {
                    R--;
                }
                else if (nums[L] + nums[R] < -nums[i]) {
                    L++;
                }
                else {
                    sol.push_back({nums[i], nums[L], nums[R]});
                    R--;
                    L++;
                }
            }
        }

        return sol;
    }
};
