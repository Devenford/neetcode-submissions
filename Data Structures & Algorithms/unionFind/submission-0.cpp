#include<unordered_map>
using namespace std;

class UnionFind {
    unordered_map<int, int> par, rank;
    int numComponents;

public:
    UnionFind(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        numComponents = n;
    }

    int find(int x) {
        int p = par[x];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if(p1==p2) {
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
        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
};
