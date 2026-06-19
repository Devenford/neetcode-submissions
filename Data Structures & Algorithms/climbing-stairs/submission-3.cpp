#include<unordered_map>
using namespace std;

class Solution {
    int ways(int n, unordered_map<int, int> &m) {
        if (n<=2) {
            return n;
        }
        if (m.count(n)) {
            return m[n];
        }

        m[n] = ways(n-1, m) + ways(n-2, m);
        return m[n];
    }
public:
    int climbStairs(int n) {
        unordered_map<int, int> m;
        return ways (n, m);
    }
};
