#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) {
            m[num] += 1;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for(pair<const int, int> &p : m) {
            freq[p.second].push_back(p.first);
        }

        vector<int> sol;
        for(int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                sol.push_back(n);
                if (sol.size() == k) {
                    return sol;
                }
            }
        }

        return sol;
        
    }
};
