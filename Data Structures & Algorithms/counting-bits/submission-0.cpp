#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1, 0);
        for(int i = 1; i <= n; i++) {
            int k = i;
            while(k>0) {
                if(k & 1 == 1) {
                    count[i]++;
                }
                k = k >> 1;
            }
        }
        return count;
    }
};
