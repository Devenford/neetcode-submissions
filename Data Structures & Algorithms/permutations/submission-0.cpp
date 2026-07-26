#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getPerms(int i, vector<int> &nums) {
        if (i == nums.size()) {
            return {{}};
        }

        vector<vector<int>> returnPerms;
        vector<vector<int>> perms = getPerms(i+1, nums);
        for (vector<int> p : perms) {
            for(int j = 0; j <= p.size(); j++) {
                vector<int> pCopy(p);
                pCopy.insert(pCopy.begin() + j, nums[i]);
                returnPerms.push_back(pCopy);
            }
        }
        return returnPerms;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        return getPerms(0, nums);
    }
};
