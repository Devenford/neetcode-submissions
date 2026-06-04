#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> numMap;
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if (numMap.count(target-num) != 0) {
                sol.push_back(numMap[target-num]);
                sol.push_back(i);
                break;
            }
            numMap[num] = i;
        }

        return sol;
    }
};
