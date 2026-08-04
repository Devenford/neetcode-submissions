#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;

class Solution { // graph is not reversed !!!!
    void dfs(int src, unordered_map<int, vector<int>> &adj, unordered_set<int> &visit, vector<vector<bool>> &reach) {
        if (visit.count(src)) {
            return;
        }

        visit.insert(src);

        for (int neighbor : adj[src]) {
            dfs(neighbor, adj, visit, reach);
            reach[src][neighbor] = true;
            for (int i = 0; i<reach[0].size(); i++) {
                if (reach[neighbor][i]) {
                    reach[src][i] = reach[neighbor][i];
                }
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (vector<int> &edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        // The prerequisites graph has no cycles (given in Q)
        vector<vector<bool>> reach(numCourses, vector<bool> (numCourses, false)); // reachability from row r to col c
        vector<bool> answer;
        unordered_set<int> visit;
        for (int i=0; i<numCourses; i++) {
            dfs(i , adj, visit, reach);
        }

        for (int i = 0; i< queries.size(); i++) {
            if (reach[queries[i][0]][queries[i][1]]) {
                answer.push_back(true);
            }
            else {
                answer.push_back(false);
            }
        }

        return answer;
    }
};