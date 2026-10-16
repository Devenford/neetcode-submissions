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
            if (heap.size() && q.size()) {
                int f = heap.top();
                pair<int, int> p = q.front(); // p = pair
                if (p.second <= cycle && p.first >= f) {
                    q.pop_front();
                    if (p.first - 1 > 0) {
                        q.push_back({p.first - 1, cycle + n + 1});
                    }
                }
                else {
                    heap.pop();
                    if (f-1 > 0) {
                        q.push_back({f-1, cycle + n + 1});
                    }
                }
            }
            else if (heap.size()){
                int f = heap.top();
                heap.pop();
                if (f-1 > 0) {
                    q.push_back({f-1, cycle + n + 1});
                }
            }
            else { // q is not empty
                pair<int, int> p = q.front(); // p = pair
                if (p.second <= cycle) {
                    q.pop_front();
                    if (p.first - 1 > 0) {
                        q.push_back({p.first - 1, cycle + n + 1});
                    }
                }
            }
        }

        return cycle;
    }
};
