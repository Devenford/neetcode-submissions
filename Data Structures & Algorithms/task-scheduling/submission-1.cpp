#include<unordered_map>
#include<utility>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char t : tasks) {
            freq[t]++;
        }

        priority_queue<int, vector<int>> heap; // max heap <int> = frequency
        for (pair<const char, int> t : freq) {
            heap.push(t.second);
        }

        deque<pair<int, int>> q; // <frequency left/remaining, next cycle>
        int cycle = 0;
        while (heap.size() || q.size()) {
            cycle++;
            while (q.size() && q.front().second <= cycle) { // When a task’s cooldown finishes, we push it back into the heap so it can be scheduled again.
                heap.push({q.front().first});
                q.pop_front();
            }
            if (heap.size()) {
                if (heap.top() - 1 > 0) {
                    q.push_back({heap.top() - 1, cycle + n + 1});
                }
                heap.pop();
            }
        }

        return cycle;
    }
};
