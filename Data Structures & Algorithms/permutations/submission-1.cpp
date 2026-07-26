#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};

        for(int n: nums) {
            vector<vector<int>> nextPerms;
            for(vector<int> p: perms) {
                for(int j=0; j<=p.size(); j++) {
                    vector<int> copyP(p);
                    copyP.insert(copyP.begin()+j, n);
                    nextPerms.push_back(copyP);
                }
            }
            perms = nextPerms;
        }

        return perms;
    }
};
