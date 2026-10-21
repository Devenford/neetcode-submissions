// Monotonically decreasing queue
#include<deque>
#include<vector>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores the indices of the nums in decreasing order (Monotonically decreasing queue)
        vector<int> sol;

        for(int R = 0; R < nums.size(); R++) {
            while (!dq.empty() && nums[R] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(R);

            if (R >= k - 1) {
                if (dq.front() <= R - k) {
                    dq.pop_front();
                }
                sol.push_back(nums[dq.front()]);
            }
        }
        
        return sol;
    }
};
