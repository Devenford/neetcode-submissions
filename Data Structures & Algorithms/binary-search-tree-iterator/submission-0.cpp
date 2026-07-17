/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode* curr;
    std::stack<TreeNode*> stack;

   public:
    BSTIterator(TreeNode* root) {
        curr = root;

        while (curr) {
            stack.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        curr = stack.top();
        stack.pop();
        int sol = curr->val;

        if (curr->right) {
            curr = curr->right;
            stack.push(curr);

            while (curr->left) {
                curr = curr->left;
                stack.push(curr);
            }
        }

        return sol;
    }

    bool hasNext() { return !stack.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */