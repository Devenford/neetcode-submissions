#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {  // 3D DP
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> prev(m+1, vector<int> (n+1, 0)); // previous dp row

        // initialize first row:
        int first0 = 0, first1 = 0;
        for (char c: strs[0]) {
            c == '0' ? first0++ : first1++;
        }

        // capacity = how many 0s or 1s are allowed
        for (int c0 = 0; c0 <= m; c0++) { // c0 = capacity of 0s and c1 = capacity of 1s
            for(int c1 = 0; c1 <= n; c1++) {
                if (first0 <= c0 && first1 <= c1) {
                    prev[c0][c1] = 1;
                }
            }
        }

        for(int i=1; i<strs.size(); i++) {
            int num0 = 0, num1 = 0;
            for (char c : strs[i]) {
                c == '0' ? num0++ : num1++;
            }

            vector<vector<int>> curr(m+1, vector<int> (n+1, 0)); // current dp row
            for (int c0 = 0; c0 <= m; c0++) { // c0 = capacity of 0s and c1 = capacity of 1s
                for(int c1 = 0; c1 <= n; c1++) {
                    curr[c0][c1] = prev[c0][c1];

                    if (num0 <= c0 && num1 <= c1) { // both must fit within their capacity
                        curr[c0][c1] = max(curr[c0][c1], 1 + prev[c0-num0][c1-num1]);
                    }
                }
            }

            prev = curr;
        }

        return prev[m][n];

    }
};