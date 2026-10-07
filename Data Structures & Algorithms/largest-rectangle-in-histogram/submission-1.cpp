#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        stack<pair<int, int>> s; // <left boundary index, height>

        for(int i=0; i<n; i++) {
            int leftBoundary = i;
            while(!s.empty() && heights[i] < s.top().second) {
                leftBoundary = s.top().first;
                maxArea = max(maxArea, (i - s.top().first) * s.top().second); // (right boundary index - left boundary index) * height
                s.pop();
            }
            s.push({leftBoundary, heights[i]});
        }

        while(!s.empty()) {
            maxArea = max(maxArea, (n - s.top().first) * s.top().second);
            s.pop();
        }

        return maxArea;
    }
};
