struct Node {
    int sum, L, R;
    Node *left, *right;

    Node(int v, int l, int r) {
        sum = v; L = l; R = r;
        left = nullptr; right = nullptr;
    }
};


class SegmentTree {
    Node* root;

    Node* build(vector<int> &nums, int l, int r) {
        if (l==r) {
            return new Node(nums[l], l, r);
        }

        Node *root_ = new Node(0, l, r);
        int M = (l+r)/2;
        root_->left = build(nums, l, M);
        root_->right = build(nums, M+1, r);
        root_->sum = root_->left->sum + root_->right->sum;
        return root_;
    }

    void Update(int index, int val, Node* curr) {
        if (curr->L==curr->R) {
            curr->sum = val;
            return;
        }

        int M = (curr->L + curr->R)/2;
        if (index > M) {
            Update(index, val, curr->right);
        }
        else {
            Update(index, val, curr->left);
        }
        curr->sum = curr->right->sum + curr->left->sum;
    }
    
    int queryRange(int l, int r, Node* curr) {
        if (l==curr->L && r==curr->R) {
            return curr->sum;
        }

        int M = (curr->L + curr->R)/2;
        if (l > M) {
            return queryRange(l, r, curr->right);
        }
        else if (r <= M) {
            return queryRange(l, r, curr->left);
        }
        else {
            return queryRange(l, M, curr->left) + queryRange(M+1, r, curr->right);
        }
    }

public:
    SegmentTree(vector<int>& nums) {
        root = build(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        Update(index, val, root);
    }
    
    int query(int l, int r) {
        return queryRange(l, r, root);
    }
};
