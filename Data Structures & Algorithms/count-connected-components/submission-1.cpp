#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    unordered_map<int, int> par, rank;

    int find(int n) {
        int p = par[n];
        while(p != par[p]) {
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

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }

        int total = n;
        for (const vector<int> &edge : edges) {
            if (Union(edge[0], edge[1])) {
                total--;
            }
            /* if the union isn't possible (since the two vertices already
            belong to the same set/component, i.e. a cycle), then the number
            of components remains the same (since all you're doing is completing
            /forming a cycle).
            */
        }

        return total;
    }
};
