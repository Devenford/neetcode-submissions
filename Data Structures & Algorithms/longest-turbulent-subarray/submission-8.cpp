#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int L = 0, length = 1, R = 1;
        char prev = '\0';  // '' char doesn't exist, '' string does
        

        while(R < arr.size()) {
            if (arr[R-1] > arr[R] && prev != '>') {
                length = max(length, R-L+1);
                prev = '>';
                R++;
            }
            else if (arr[R-1] < arr[R] && prev != '<') {
                length = max(length, R-L+1);
                prev = '<';
                R++;
            }
            else {
                R = (arr[R-1] == arr[R] ? R+1 : R);
                L = R-1;
                prev = '\0';
            }
        }

        return length;
    }
};