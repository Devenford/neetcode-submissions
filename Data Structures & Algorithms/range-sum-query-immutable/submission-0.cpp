#include<vector>
using namespace std;

class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */