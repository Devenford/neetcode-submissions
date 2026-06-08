#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> countSet;
        for (int &num : nums) {
            if (countSet.count(num) != 0) {
                return true;
            }
            countSet.insert(num);
        }

        return false;
    }
};