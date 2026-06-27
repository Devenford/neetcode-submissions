#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX, L = 0, sum = 0;

        for(int R = 0; R<nums.size(); R++) {
            sum += nums[R];
            while(sum >= target) {
                length = min(length, R-L+1);
                sum -= nums[L];
                L++;
            }
        }

        return length == INT_MAX ? 0 : length;
    }
};