#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        unordered_map<int, pair<int, int>> greatestBar; // upto each index
        // <index, pair<greatestLeftBar, greatestRightBar>>

        int maxL = 0, maxR = 0;   
        // maxL = max height from left-hand side
        // maxR = max height from right-hand side
        for (int i = 0; i<height.size(); i++) {
            maxL = max(maxL, height[i]);
            greatestBar[i].first = maxL;

            maxR = max(maxR, height[height.size()-1-i]);
            greatestBar[height.size()-1-i].second = maxR;
        }

        int area = 0;
        for (int i = 0; i<height.size(); i++) {
            area += min(greatestBar[i].first, greatestBar[i].second) - height[i];
        }

        return area;
    }
};
