#include<unordered_map>
using namespace std;

class UnionFind {
    unordered_map<int, int> rank; // height
    unordered_map<int, int> parent;
    int numComponents;

public:
    UnionFind(int n) {
        for(int i = 1; i<=n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        numComponents = n;
    }

    int find(int x) { // find root
        int p = parent[x];
        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y) ? true : false;
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int p1  = find(x), p2 = find(y);
        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        }
        else if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        }
        else {
            parent[p2] = p1;
            rank[p1]++;
        }

        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
};
