int Count(int n, int sum, vector<int> &data) {
    if(sum>n) {
        return 0;
    }
    if(sum==n) {
        return 1;
    }
    if(data[sum]!=-1) {
        return data[sum];
    }

    int x =  Count(n, sum+1, data) + Count(n, sum+2, data);
    data[sum] = x;
    return x;
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> data(n+1, -1);
        return Count(n, 0, data);
    }
};
