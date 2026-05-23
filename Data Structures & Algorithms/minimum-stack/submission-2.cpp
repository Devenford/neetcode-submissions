class MinStack {
    vector<int> s;
    vector<int> minS;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push_back(val);
        if(minS.empty() || val<=minS.back()) {
            minS.push_back(val);
        }
    }
    
    void pop() {
        if(s.back() == minS.back()) {
            minS.pop_back();
        }
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minS.back();
    }
};
