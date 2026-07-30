#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

class Solution {

public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        unordered_set<int> visit; // visited
        int cost = 0; // min total cost or wt
        unordered_map<int, vector<pair<int, int>>> adjlist; 
        // <u, {<v, wt>}>

        for (vector<int> &edge: edges) {
            adjlist[edge[0]].push_back(pair<int,int> {edge[1], edge[2]});
            adjlist[edge[1]].push_back(pair<int,int> {edge[0], edge[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});  // <wt, v1, v2>

        while (visit.size() < n && !minHeap.empty()) {
            vector<int> edge = minHeap.top();
            minHeap.pop();
            int w = edge[0], v1 = edge[1], v2 = edge[2];
            if (visit.count(v2)) {
                continue;
            }
            visit.insert(v2);
            cost += w;

            for (pair<int,int> p : adjlist[v2]) {
                int v3 = p.first, w3 = p.second;
                if (!visit.count(v3)) {
                    minHeap.push({w3, v2, v3});
                }
            }
        }

        return visit.size() == n ? cost : -1;
    }
};

