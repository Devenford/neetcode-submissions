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

        return sol;
    }
};
