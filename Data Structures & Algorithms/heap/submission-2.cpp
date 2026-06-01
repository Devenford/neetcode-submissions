#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void percolate_down(int i) {
        // percolate down from root
        while(2*i<heap.size()) {
            if(2*i+1<heap.size() && heap[2*i+1]<heap[i] && heap[2*i+1]<heap[2*i]) {
                int temp = heap[i];
                heap[i] = heap[2*i+1];
                heap[2*i+1] = temp;
                i = 2*i + 1;
            }
            else if (heap[2*i]<heap[i]) {
                int temp = heap[i];
                heap[i] = heap[2*i];
                heap[2*i] = temp;
                i *= 2;
            }
            else {
                break;
            }
        }
    }

public:
    MinHeap() {
        heap.push_back(0);
    }

    void push(int val) {
        if(heap.size()==1) {
            heap.push_back(val);
            return;
        }

        heap.push_back(val);
        int i = heap.size() - 1;
        //percolate up
        while(i>1 && heap[i] < heap[i/2]) {
            int temp = heap[i/2];
            heap[i/2] = heap[i];
            heap[i] = temp;
            i /= 2;
        }
    }

    int pop() {
        if (heap.size()==1) {
            return -1;
        }
        if (heap.size()==2) {
            int popped_element = heap[1];
            heap.pop_back();
            return popped_element;
        }

        int popped_element = heap[1];
        heap[1] = heap[heap.size()-1];  //swap root and last element
        heap.pop_back();
        // percolate down from root
        percolate_down(1);
        return popped_element;
    }

    int top() {
        if(heap.size()>1) {
            return heap[1];
        }

        return -1;
    }

    void heapify(const vector<int>& arr) {
        if(arr.size()==0) {
            return;
        }
        
        heap = arr;
        heap.push_back(heap[0]);
        heap[0] = 0;

        int curr = (heap.size()-1)/2; // start from the last non-leaf node
        while (curr > 0) {
            //percolate down
            percolate_down(curr);
            curr--;
        }
    }
};
