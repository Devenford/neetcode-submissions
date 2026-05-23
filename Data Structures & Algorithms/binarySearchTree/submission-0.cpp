class TreeMap {
    struct TreeNode {
        int key, val;
        TreeNode *left, *right;

        TreeNode(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
    } *root;

    TreeNode* insertNode(TreeNode *node, int key, int val) {
        if(node==nullptr) {
            return new TreeNode(key, val);
        }

        if(key > node->key) {
            node->right = insertNode(node->right, key, val);
        }
        else if (key < node->key) {
            node->left = insertNode(node->left, key, val);
        }
        else {
            node->val = val;
        }

        return node;
    }

    int searchNode(TreeNode *node, int key) {
        if(node==nullptr) {
            return -1;
        }

        if(key<node->key) {
            return searchNode(node->left, key);
        }
        else if (key>node->key) {
            return searchNode(node->right, key);
        }
        else {
            return node->val;
        }
    }

    TreeNode* findSmallest(TreeNode *node) {
        if(node==nullptr) {
            return nullptr;
        }

        if(node->left==nullptr) {
            return node;
        }
        else {
            return findSmallest(node->left);
        }
    }

    TreeNode* findLargest(TreeNode *node) {
        if(node==nullptr) {
            return nullptr;
        }

        if(node->right==nullptr) {
            return node;
        }
        else {
            return findLargest(node->right);
        }
    }

    TreeNode* deleteNode(TreeNode *node, int key) {
        if(node==nullptr) {
            return nullptr;
        }

        if(key<node->key) {
            node->left = deleteNode(node->left, key);
        }
        else if(key>node->key) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if(node->left==nullptr && node->right==nullptr) {
                delete node;
                return nullptr;
            }

            if(node->left==nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right==nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                TreeNode* temp = findSmallest(node->right);
                node->key = temp->key;
                node->val = temp->val;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        return node;
    }

    void inOrder(TreeNode *node, vector<int> &traversed) {
        if(node==nullptr) {
            return;
        }

        inOrder(node->left, traversed);
        traversed.push_back(node->key);
        inOrder(node->right, traversed);
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        root = insertNode(root, key, val);
    }

    int get(int key) {
        return searchNode(root, key);
    }

    int getMin() {
        TreeNode* temp = findSmallest(root);
        if(temp) {
            return temp->val;
        }
        else {
            return -1;
        }
    }

    int getMax() {
        TreeNode *temp = findLargest(root);
        if(temp) {
            return temp->val;
        }
        else {
            return -1;
        }
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> traversed;
        inOrder(root, traversed);
        return traversed;
    }
};
