#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class UnionFind {
    unordered_map<int, int> rank;
    unordered_map<int, int> par;

    public:
    UnionFind(int n) {
        for(int i = 0; i< n; i++) {
            rank[i] = 0;
            par[i] = i;
        }
    }

    int find(int n) {
        int p = par[n];
        while(par[p] != p) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) { // cycle
            return false;
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        }
        else if (rank[p2] > rank[p1]) {
            par[p1] = p2;
        }
        else {
            par[p2] = p1;
            rank[p1]++;
        }

        return true;
    }
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for (vector<int> &edge : edges) {
            int n1 = edge[0], n2 = edge[1], wt = edge[2];
            minHeap.push({wt, n1, n2});
        }

        int mstNumEdges = 0;
        UnionFind uf(n);
        int cost = 0;
        while(mstNumEdges < n-1) {
            if (minHeap.empty()) { // the graph is disconnected, i.e. mst.size() is still < n-1 even though the minHeap is empty
                return -1;
            }

            vector<int> edge = minHeap.top();
            minHeap.pop();
            int wt = edge[0], n1 = edge[1], n2 = edge[2];

            if (uf.Union(n1, n2)) {
                mstNumEdges++;
                cost += wt;
            }
        }

        return cost;
    }
};
