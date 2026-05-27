#include <iostream>
#include <vector>

class KthLargest {  // min heap
    int size_limit;
    vector<int> heap;
    
public:
    KthLargest(int k, vector<int>& nums) {
        size_limit = k + 1;  //contains k largest elements
        heap.push_back(0);
        for(int num: nums) {
            add_ele(num);
        }
    }

    void pop() {
        heap[1] = heap[heap.size()-1];
        heap.pop_back();
        //percolate down
        int i = 1;
        while(2*i < heap.size()) {
            if(2*i+1 < heap.size() && heap[2*i+1]<heap[2*i] && heap[2*i+1]<heap[i]) {
                int temp = heap[i*2+1];
                heap[2*i+1] = heap[i];
                heap[i] = temp;
                i = 2*i + 1;
            }
            else if (heap[2*i]<heap[i]) {
                int temp = heap[i*2];
                heap[2*i] = heap[i];
                heap[i] = temp;
                i*=2;
            }
            else {
                break;
            }
        }
    }
    
    void add_ele(int val) {
        heap.push_back(val);
        int i = heap.size()-1;
        // percolate up
        while(i>1 && heap[i]<heap[i/2]) {
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i/=2;
        }

        if(heap.size() > size_limit) { // pop root element
            pop();
        }
    }

    int add(int val) {
        add_ele(val);
        return heap[1];
    }
};
