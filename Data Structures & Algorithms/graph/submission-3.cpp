#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

class Graph {
    unordered_map<int, unordered_set<int>> adjList;

public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjList[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if(adjList.find(src) == adjList.end() || adjList[src].find(dst) == adjList[src].end()) {
            return false;
        }

        adjList[src].erase(dst);
        return true;
    }

    bool hasPath(int src, int dst) {
        queue<int> q;
        unordered_set<int> visit;
        visit.insert(src);
        q.push(src);

        while(q.size()) {
            int curr = q.front();
            q.pop();
            if (curr==dst) {
                return true;
            }

            for(int neighbor : adjList[curr]) {
                if(visit.count(neighbor)==0) {
                    q.push(neighbor);
                    visit.insert(neighbor);
                }
            }
        }

        return false;
    }
};
