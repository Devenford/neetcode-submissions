#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
Each prerequisite[] vector is a directed edge from prerequisite[1] to prerequisite[0]
You need to check if the graph is a DAG, a directed acyclic graph
No cycles

DFS is better/is used since you can track the current path naturally via 
the recursion stack, i.e. a node being visited twice on the same recursive 
path means there's a back-edge, i.e. a cycle.
*/

class Solution {
    bool dfs(int node, unordered_map<int, vector<int>> &adjList, unordered_set<int> &visit, unordered_set<int> &processed) {
        if (visit.count(node)) {
            return false;
        }
        if (processed.count(node)) { // already safe, skip (prevents 
        // revisiting a node through another path)
            return true; 
        } // If node X was already fully explored (no cycle found), 
        // any other path that reaches X can immediately return true 
        // without re-running DFS through X's entire subtree.

        visit.insert(node);
        processed.insert(node);

        for (int neighbor: adjList[node]) {
            if (!dfs(neighbor, adjList, visit, processed)) {
                return false;
            }
        }

        visit.erase(node);
        /* **** IMPORTANT NOTE:
        A cycle only occurs when a node is revisited on the current path:
        A -> B -> C -> A
        It doesn't occur when a processed node is revisited:
        A -> B and A -> C -> B   here, B is revisited but there's no cycle
        Thus, visit.erase(node) is required (to only check the current path)
        */ 
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visit;  //stores the visited vertices on the current dfs path
        unordered_set<int> processed;  //processed nodes

        for (vector<int> &p : prerequisites) {  // p = pair
            adjList[p[1]].push_back(p[0]);
        }

        for(int i=0; i<numCourses; i++) {
            if (processed.count(i)==0) {
                if (!dfs(i, adjList, visit, processed)) {
                    return false;
                }
            } // i = starting vertex
        }

        return true;
    }
};
