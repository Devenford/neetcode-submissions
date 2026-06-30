#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size() - 1, maxWater = 0;

        while (L<R) {
            int minH = min(heights[L], heights[R]);
            int water = minH * (R - L);
            maxWater = max(maxWater, water);
            heights[L] < heights[R] ? L++ : R--;
        }

        return maxWater;
    }
};
