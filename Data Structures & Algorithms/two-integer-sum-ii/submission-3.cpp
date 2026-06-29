#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size()-1;

        while(L < R) {
            if (numbers[L] + numbers[R] > target) {
                R--;
            }
            else if (numbers[L] + numbers[R] < target) {
                L++;
            }
            else {
                return vector<int>{L+1, R+1}; // 1-indexed, not zero-indexed
            }
        }

        return vector<int>{};
    }
};
