#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    priority_queue<int> heap; //max heap

public:
    int lastStoneWeight(vector<int>& stones) {
        for (int stone : stones) {
            heap.push(stone);
        }

        while(heap.size()>1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            //x is either > or == y
            if(x==y) {
                continue;
            }
            else {       // x > y
                heap.push(x-y);
            }
        }

        if(heap.size()==0) {
            return 0;
        }

        return heap.top();
    }
};
