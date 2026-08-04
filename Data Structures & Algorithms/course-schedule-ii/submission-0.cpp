#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution { // graph is already reversed!!!!
    bool dfs(int src, int numCourses, unordered_map<int, vector<int>> &adj, unordered_set<int> &visit, unordered_set<int> &path, vector<int> &topSort) {
        // post-order dfs
        if (path.count(src)) { // cycle
            return false;
        }
        if (visit.count(src)) {
            return true;
        }

        path.insert(src);
        visit.insert(src);
        for (int neighbor : adj[src]) {
            if (!dfs(neighbor, numCourses, adj, visit, path, topSort)) {
                return false;
            }
        }
        
        topSort.push_back(src);
        path.erase(src);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; // adjlist
        for (vector<int> &edge : prerequisites)  {
            adj[edge[0]].push_back(edge[1]);
        }

        unordered_set<int> visit;
        unordered_set<int> path;
        vector<int> topSort;
        for (int i=0; i<numCourses; i++) {
            if (!dfs(i, numCourses, adj, visit, path, topSort)) {
                return {};
            }
        }
        return topSort;
    }
};
