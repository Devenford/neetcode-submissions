#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms = {{}};

        for(int n: nums) {
            vector<vector<int>> nextPerms;
            for(vector<int> p: perms) {
                for(int j=0; j<=p.size(); j++) {
                    vector<int> copyP(p);
                    copyP.insert(copyP.begin()+j, n);
                    nextPerms.push_back(copyP);
                    if (j<p.size() && n == p[j]) {
                        break;
                    } 
                }
            }
            perms = nextPerms;
        }

        return perms;
    }
};