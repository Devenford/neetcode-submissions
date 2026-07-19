#include<queue>
using namespace std;

class MedianFinder {
    priority_queue<int> small; // max heap
    priority_queue<int, vector<int>, greater<int>> large; // min heap

public:
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);
        if(!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return (double) small.top();
        }
        else if (large.size() > small.size()) {
            return (double) large.top();
        }
        else {
            return (double) (small.top()+large.top())/2.0;
        }
    }
};
