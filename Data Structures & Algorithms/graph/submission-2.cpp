#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

class Graph {
    unordered_map<int, vector<int>> adjList;

public:
    Graph() {}

    void addEdge(int src, int dst) {
        if(adjList.count(src)) {
            vector<int>::iterator it = adjList[src].begin();
            while(it != adjList[src].end()) {
                if(*it == dst) {
                    return;
                }
                it++;
            }
        }

        adjList[src].push_back(dst);
    }

    bool removeEdge(int src, int dst) {
        if(adjList.count(src)==0) {
            return false;
        }

        vector<int> :: iterator it = adjList[src].begin();
        while (it != adjList[src].end()) {
            if (*it == dst) {
                adjList[src].erase(it);
                return true;
            }
            it++;
        }

        return false;
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
