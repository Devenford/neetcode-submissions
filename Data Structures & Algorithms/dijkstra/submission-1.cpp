#include<vector>
#include<unordered_map>
#include<queue>
using std::vector;
using std::unordered_map;
using std::priority_queue;

class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int,int>>> adjlist; // <source, <destination, wt>>
        for (vector<int> &edge: edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adjlist[s].push_back(pair<int,int> {d, w});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        // <cumulative path length, vertex> 
        unordered_map<int, int> shortestPaths; 
        // <shortest path length from source, vertex>
        minHeap.push(pair<int,int> {0, src}); 
        /* we want the minHeap to be ordered by the path length (shortest 
        path length is popped first), so the path length is before the 
        vertex: {0, src}
        */
        while(!minHeap.empty()) { // v = vertex
            pair<int,int> p = minHeap.top();
            int w1 = p.first, v1 = p.second;
            minHeap.pop();

            if (shortestPaths.count(v1) > 0) { // shortest path has already been determined for this vertex
                continue;
            }

            shortestPaths[v1] = w1;
            for (pair<int, int> &p : adjlist[v1]) {
                int v2 = p.first, w2 = p.second;
                if (shortestPaths.count(v2) == 0) {
                    minHeap.push(pair<int,int> {w1 + w2, v2});
                }
            }
        }

        // for unreachable vertices from source vertex
        for(int i=0; i<n ; i++) {
            if (shortestPaths.count(i) == 0) {
                shortestPaths[i] = -1;
            }
        }

        return shortestPaths;
    }
};
