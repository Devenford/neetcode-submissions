#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int leftMax = height[L], rightMax = height[R];
        // leftMax = greatest bar to the left of the current index
        // rightMax = greatest bar to the right of the current index

        // Similar to Two Integer Sum II problem
        int area = 0;
        /*
        Every iteration computes the water for the index that the pointer 
        moves onto, not the index it was previously on: 
        area += leftMax - height[L];
        or
        area += rightMax - height[R];
        */
        while(L<R) {
            if (leftMax < rightMax) {
                L++; // we increment first since the first index can't have any water above it, since it would spill over the edge of the graph
                leftMax = max(leftMax, height[L]);
                area += leftMax - height[L];
            }
            else {
                R--; // // we decrement first since the last index can't have any water above it, since it would spill over the edge of the graph
                rightMax = max(rightMax, height[R]);
                area += rightMax - height[R];
            }
        }
        /* 
        The amount of water trapped at an index i = min(height[l], height[r]) - height[i]
        where, l = tallest/greatest bar to the left of index i
        r = tallest/greatest bar to the right of index i
        */

        return area;
    }
};
