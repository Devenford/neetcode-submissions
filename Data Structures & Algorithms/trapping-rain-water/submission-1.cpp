#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n), rightMax(n); // upto each index
        // leftMax[i] = greatest bar to the left of index i
        // rightMax[i] = greatest bar to the right of index i

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for (int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
            rightMax[n-1-i] = max(rightMax[n-i], height[n-1-i]);
        }

        int area = 0;
        for (int i = 0; i<n; i++) {
            area += min(leftMax[i], rightMax[i]) - height[i];
        }
        /* 
        The amount of water trapped at an index i = min(height[l], height[r]) - height[i]
        where, l = tallest/greatest bar to the left of index i
        r = tallest/greatest bar to the right of index i
        */

        return area;
    }
};
