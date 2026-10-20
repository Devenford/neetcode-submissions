#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> sol;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        // <number, index position>

        for(int i=0; i<nums.size(); i++) {
            maxHeap.push({nums[i], i});
            if (i >= k - 1) {
                while (maxHeap.top().second <= i - k) {
                    maxHeap.pop();
                }
                sol.push_back(maxHeap.top().first);
            }
        }

        // We process each window by adding elements to the heap along with their indices to track whether the maximum value is still within the current window. We can ignore those elements that are no longer part of the current window, except when the maximum value is outside the window. In that case, we remove elements from the max-heap until the maximum value belongs to the current window. Why? Because those elements will be eventually removed when the maximum element goes out of the window.

        return sol;
    }
};
