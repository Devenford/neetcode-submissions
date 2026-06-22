class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1);
        int offset = 1; // most recent power of 2

        for(int i=1; i<=n; i++) {
            if(offset * 2 == i) {
                offset = i;
            }
            count[i] = 1 + count[i - offset];
        }
        return count;
    }
};
