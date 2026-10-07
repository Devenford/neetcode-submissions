#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        stack<int> s; // <bar index>

        // it's a monotonically increasing stack, i.e. only heights in increasing order are stored
        // Ex:   1, 2, 3, 5
        // Ex:   If a smaller height is encountered, then the stack is popped until the monotonically increasing condition is met again: 1, 2, 3, 5, 2 => 1, 2, 2
        for(int i=0; i<=n; i++) {
            while(!s.empty() && (i == n || heights[i] <= heights[s.top()])) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        return maxArea;
    }
};
