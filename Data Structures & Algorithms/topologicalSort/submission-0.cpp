#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    bool dfs(int src, unordered_set<int> &visit, unordered_set<int> &path, unordered_map<int, vector<int>> &adj, vector<int> &topSort) {
        if (path.count(src)) { // cycle exists
            return false;
        }
        if (visit.count(src)) { // already visited
            return true;
        }

        visit.insert(src);
        path.insert(src);
        // perform postorder dfs
        for (int neighbor : adj[src]) {
            if (!dfs(neighbor, visit, path, adj, topSort)) {
                return false;
            }
        }
        // process node
        topSort.push_back(src);
        path.erase(src);
        return true;
    }

public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj; // adjlist
        for (vector<int> &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        unordered_set<int> visit;
        unordered_set<int> path;
        vector<int> topSort;

        for(int i=0; i<n; i++) {
            if (!dfs(i, visit, path, adj, topSort)) {
                return {};
            }
        }

        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
};
