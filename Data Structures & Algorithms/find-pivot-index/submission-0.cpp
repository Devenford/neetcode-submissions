#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum, postfixSum;
        int presum = 0, postsum = 0, n = nums.size();

        prefixSum.push_back(0);
        postfixSum.push_back(0);

        for (int i=0; i<n-1; i++) {
            presum += nums[i];
            postsum += nums[n-i-1];
            prefixSum.push_back(presum);
            postfixSum.push_back(postsum);
        }
        reverse(postfixSum.begin(), postfixSum.end());

        for(int i=0; i<n; i++) {
            if(prefixSum[i]==postfixSum[i]) {
                return i;
            }
        }

        return -1;
    }
};