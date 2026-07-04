#include<vector>
#include<unordered_map>
using namespace std;

/* We can't use 2-pointers nor a sliding window, since the numbers can be 
positive, negative, or 0: -1,000 <= nums[i] <= 1,000. So, we can't guarantee
that the sum will keep increasing nor decreasing.
Ex: 2 = 2, 2 + -1 + 1 = 2, -1 + 1 + 2 = 2, and 2 = 2 in nums = [2,-1,1,2], k = 2
Here, the sum can become 2 again later on if the sum of the other numbers 
in the contiguous subarray cancel each other out/become 0. (2 + -1 + 1 = 2)
*/

/* In hash map: unordered_map<prefixSum, count>
prefixSum is the sum that we can remove from the front/prefix of the 
subarray to make it equal to k.
count is the the number of times that prefixSum has occurred
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currSum = 0, result = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0]++;

        for(int n: nums) {
            currSum += n;
            if (prefixSums[currSum-k] > 0) {
                result += prefixSums[currSum-k];
            }
            prefixSums[currSum]++;
        }

        return result;
    }
};