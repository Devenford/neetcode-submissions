#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    unordered_map<int, int> par, rank;

    int find(int n) {  // find root ("p" parent root)
        int p = par[n];
        while(p!=par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool Union(int n1, int n2) { // combine two disjoint sets
        int p1 = find(n1), p2 = find(n2);
        
        if (p1 == p2) {   // belongs to the same set, i.e. cycle!!!
            return false;
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        }
        if (rank[p1] < rank[p2]) {
            par[p1] = p2;
        }
        else {
            par[p2] = p1;
            rank[p1]++;
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> solution;

        for(int i=0; i<edges.size(); i++) { // number of edges (n) = number of vertices (n)
            par[i] = i;
            rank[i] = 0;
        }

        for (vector<int> edge : edges) {
            if (!Union(edge[0], edge[1])) {
                solution.push_back(edge[0]);
                solution.push_back(edge[1]);
                break;
            }
        }
        return solution;
    }
};
