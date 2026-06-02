#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    priority_queue<int, vector<int>, greater<int>> heap; // min heap 
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int num : nums) {
            if(heap.size()==k) {
                if(num > heap.top()) {
                    heap.pop();
                    heap.push(num);
                }
            }
            else {
                heap.push(num);
            }
        }

        return heap.top();
    }
};
