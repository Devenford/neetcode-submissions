// with Kruskal's MST algorithm
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

class UnionFind {
    unordered_map<int, int> par;
    unordered_map<int, int> rank;

    public:
    UnionFind(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int n) {
        int p = par[n];
        while (par[p] != p) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        }
        else if (rank[p1] < rank[p2]) {
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
    bool checkMST(int n, vector<vector<int>> &edges, int mstCost, int skipIndex, int includeIndex) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int currMstCost = 0;
        int mstSize = 0; // number of edges in mst
        UnionFind uf(n);

        for (int i=0; i < edges.size(); i++) {
            if (skipIndex != -1 && i == skipIndex) { // skip that edge
                continue;
            }
            if (includeIndex != -1 && i == includeIndex) { // skip the edge and add it later, forcibly
                continue;
            }
            minHeap.push({edges[i][2], edges[i][0], edges[i][1]});
            // {wt, n1, n2}
        }

        if (includeIndex != -1) { // forcibly add edge
            int n1 = edges[includeIndex][0], n2 = edges[includeIndex][1], wt = edges[includeIndex][2];
            uf.Union(n1, n2);
            currMstCost += wt;
            mstSize++;
        }

        while(mstSize < n-1) {
            if (minHeap.empty()) { // the graph is disconnected, i.e. mst.size() is still < n-1 even though the minHeap is empty
                return false;
            }
            vector<int> edge = minHeap.top();
            minHeap.pop();
            int wt = edge[0], n1 = edge[1], n2 = edge[2];

            if (uf.Union(n1, n2)) {
                currMstCost += wt;
                mstSize++;
            }
        }

        return currMstCost == mstCost ? true : false;
        // false = not an MST
        // only two options exist, either currMstCost > mstCost or currMstCost == mstCost
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int mstCost = 0;
        int mstSize = 0; // number of edges in mst
        UnionFind uf(n);

        for (vector<int> &edge : edges) {
            minHeap.push({edge[2], edge[0], edge[1]});
            // {wt, n1, n2}
        }

        while(mstSize < n-1) {
            if (minHeap.empty()) { // the graph is disconnected, i.e. mst.size() is still < n-1 even though the minHeap is empty
                mstCost = 0;
                break;
            }

            vector<int> edge = minHeap.top(); // {wt, n1, n2}
            minHeap.pop();
            int wt = edge[0], n1 = edge[1], n2 = edge[2];

            if (uf.Union(n1, n2)) {
                mstCost += wt;
                mstSize++;
            }
        }

        unordered_set<int> critical; // critical edges
        unordered_set<int> pseudo; // pseudo-critical edges

        for (int i = 0; i < edges.size(); i++) {
            // exclude edge
            if (!checkMST(n, edges, mstCost, i, -1)) { 
                // excluding edge does not form mst, then it must be critical
                 critical.insert(i);
                 continue;
            }

            // If excluding the edge still forms an mst, it may be a pseudo edge or a useless/non-mst edge. Forcibly include it to determine which one it is:
            // forcibly include edge
            if (checkMST(n, edges, mstCost, -1, i)) {
                // forcibly including the edge also builds an mst, thus it must be a pseudo edge
                pseudo.insert(i);
            }
        }

        vector<vector<int>> sol = {{}, {}};
        for (int i : critical) {
            sol[0].push_back(i);
        }
        for (int i : pseudo) {
            sol[1].push_back(i);
        }

        return sol;
    }
};