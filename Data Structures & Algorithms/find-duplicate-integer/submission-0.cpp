#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> exists;
        for (int n : nums) {
            if (exists.count(n)) {
                return n;
            }
            exists.insert(n);
        }
        return -1;
    }
};
