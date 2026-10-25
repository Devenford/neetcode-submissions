// Union-Find
// A tree is an acyclic connected graph (i.e. no. of connected components = 1)
#include<vector>
#include<unordered_map>
using namespace std;

class UnionFind {
    unordered_map<int, int> par; // root parent
    unordered_map<int, int> rank; // rank of node

    public:
    int components = 0;
    
    UnionFind(int n) {
        for(int i = 0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        components = n;
    }

    int find(int i) { // find the root parent
        int p = par[i];
        while(par[p] != p) { // path compression
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool union_(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) { // cycle detected
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

        components--;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (vector<int> &edge : edges) {
            if (!uf.union_(edge[0], edge[1])) {
                return false;
            }
        }

        return uf.components == 1;
    }
};
