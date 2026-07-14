#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache;
        for(int num: nums) {
            cache.insert(num);
        }

        int maxLen = 0;
        for (int num: nums) {
            if (cache.count(num-1)==0) { // if num - 1 is not in the set, then num is the start of a sequence.
                int len = 0;
                while(cache.count(num)) {
                    len++;
                    num++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};
