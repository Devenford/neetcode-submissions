// DFS version for cycle detection
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    bool dfs (int i, int parent, unordered_set<int> &visit, unordered_map<int, vector<int>> &adjlist) {
        if (visit.count(i)) {
            return false;
        }

        visit.insert(i);
        for (int neighbor : adjlist[i]) {
            if (neighbor == parent) { // a parent node, which would already have been visited, would cause a false cycle to be detected
                continue;
            }
            if (!dfs(neighbor, i, visit, adjlist)) {
                return false;;
            }
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        for (vector<int> &e : edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
            // undirected graph
        }

        unordered_set<int> visit;
        if (!dfs(0, -1, visit, adjlist)) {
            return false;
        }

        return visit.size() == n; // all the nodes have been visited in a single dfs search, i.e. a single connected component exists
    }
};
