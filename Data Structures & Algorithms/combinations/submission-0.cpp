#include<vector>
using namespace std;

class Solution {
    void getCombs(int i, vector<int> &currComb, vector<vector<int>> &sol, int n, int k) {
        if (currComb.size() == k) {
            sol.push_back(currComb);
            return;
        }
        if (i > n) return;

        for(int j = i; j<=n; j++) {
            currComb.push_back(j);
            getCombs(j+1, currComb, sol, n, k);
            currComb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> currComb;
        getCombs(1, currComb, sol, n, k);
        return sol;
    }
};