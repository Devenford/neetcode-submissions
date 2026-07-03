#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixPdt(n, 1);
        vector<int> suffixPdt(n, 1);

        for(int i=1; i<n; i++) {
            prefixPdt[i] = prefixPdt[i-1] * nums[i-1];
            suffixPdt[n-1-i] = suffixPdt[n-i] * nums[n-i];
        }

        vector<int> output(n);

        for(int i=0; i<n; i++) {
            output[i] = prefixPdt[i] * suffixPdt[i];
        }

        return output;
    }
};
