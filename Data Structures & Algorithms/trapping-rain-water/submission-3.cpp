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

        Water at any position depends on the shorter wall between the left 
        and right sides. So if the left wall is shorter, the right wall 
        can't help us, i.e. water is limited by the left side. That means we 
        safely move the left pointer inward and calculate how much water 
        can be trapped there. Similarly, if the right wall is shorter, 
        we move the right pointer left.

        For example in: height = [0, 3, 0, 4, 5, 1, 0, 2, 1, 2], n = 10
        If L = 1 and R = 9, leftMax = 3 and rightMax = 2.
        So, rightMax is smaller, and at index pos R-- = 9-1 = 8 rightMax = 2.
        Thus, at index pos 8, the largest bar to the right is known to be 2,
        and the largest bar to the left so far is 3. However, even if a larger
        bar exists to the left of index pos 8 (larger leftMax), it wouldn't be 
        it smaller than rightMax since rightMax is already smaller than the current
        leftMax.
        Therefore, even if we cannot be sure that leftMax = 3 is the largest bar
        to the left of index pos 8, we can be sure that the rightMax = 2 is the 
        largest bar to the right of index pos 8 and is also smaller than leftMax.
        The only the minimum of leftMax and rightMax matters:
        The amount of water trapped at an index i = min(height[l], height[r]) - height[i]

        The same is true while processing an index on the left side (L++).
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
