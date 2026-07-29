#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adjlist;
        for(vector<int> &edge: times) {
            adjlist[edge[0]].push_back(pair<int,int> {edge[1], edge[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int, int> shortestPaths;
        minHeap.push(pair<int,int> {0, k});
        int greatest = 0;
        while(!minHeap.empty()) {
            pair<int,int> p = minHeap.top();
            minHeap.pop();
            int w1 = p.first, v1 = p.second;

            if (shortestPaths.count(v1) > 0) {
                continue;
            }
            shortestPaths[v1] = w1;
            if (shortestPaths.size() == n) {
                return w1;
            }

            for (pair<int,int> &p : adjlist[v1]) {
                int v2 = p.first, w2 = p.second;
                if (shortestPaths.count(v2) == 0) {
                    minHeap.push(pair<int,int> {w1 + w2, v2});
                }
            } 
        }

        return -1;
    }
};
