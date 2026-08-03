#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

// Topological sort
class Solution { // graph is already reversed!!!!!
    bool dfs(int src, unordered_map<int, vector<int>> &adj, unordered_set<int> &path, unordered_set<int> &visit) {
        if (path.count(src)) { // cycle exists
            return false;
        }
        if (visit.count(src)) {
            return true;
        }

        path.insert(src);
        visit.insert(src);
        for (int neighbor : adj[src]) {
            if (!dfs(neighbor, adj, path, visit)) {
                return false;
            }
        }
        path.erase(src);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        unordered_set<int> visit;
        unordered_set<int> path;
        for (int i=0; i<numCourses; i++) {
            if (!dfs(i, adj, path, visit)) {
                return false;
            }
        }
        return true;
    }
};
