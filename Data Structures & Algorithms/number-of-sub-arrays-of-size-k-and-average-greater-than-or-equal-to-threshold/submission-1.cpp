#include<vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, L = 0, count=0;

        for(int R = 0; R<arr.size(); R++) {
            if(R-L+1 > k) {
                sum -= arr[L++];
            }
            sum += arr[R];
            if (sum/k >= threshold && R+1 >= k) { 
            // R+1 >= k ensures that the window is always of size k
                count++; 
            }
        }

        return count;
    }
};