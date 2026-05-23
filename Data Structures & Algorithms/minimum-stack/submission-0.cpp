class MinStack {
    vector<int> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return *min_element(s.begin(), s.end());
    }
};
