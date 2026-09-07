#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // <number, count>
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;

        for(int n : nums) {
            m[n]++;
        }

        for(auto &p : m) {
            maxHeap.push({p.second, p.first});
        }

        vector<int> sol;
        for(int i=0; i<k; i++) {
            pair<int, int> p = maxHeap.top();
            maxHeap.pop();
            sol.push_back(p.second);
        }
        return sol;
    }
};
