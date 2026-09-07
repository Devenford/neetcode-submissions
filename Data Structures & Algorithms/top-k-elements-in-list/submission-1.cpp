#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // <number, count>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int n : nums) {
            m[n]++;
        }

        for(auto &p : m) {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> sol;
        for(int i=0; i<k; i++) {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            sol.push_back(p.second);
        }
        return sol;
    }
};
