#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int &num : nums) {
            if (countMap.count(num) == 0) {
                countMap[num] = 1;
            } else {
                return true;
            }
        }

        return false;
    }
};