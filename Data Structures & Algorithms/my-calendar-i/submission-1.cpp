struct Node {
    int start, end;    // start = startTime and end = endTime
    Node *left, *right;

    Node(int startTime, int endTime) : start(startTime), end(endTime), left(nullptr), right(nullptr) {}
};

class MyCalendar {
    Node *root = nullptr;

    bool insert(Node *node, int start, int end) {
        if (end <= node->start) {
            if (!node->left) {
                node->left = new Node(start, end);
                return true;
            }
            return insert(node->left, start, end);
        }
        else if (start >= node->end) {
            if (!node->right) {
                node->right = new Node(start, end);
                return true;
            }
            return insert(node->right, start, end);
        }
        else {
            return false;  // time overlaps
        }
    }
    
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        if (!root) {
            root = new Node(startTime, endTime);
            return true;
        }
        return insert(root, startTime, endTime);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */