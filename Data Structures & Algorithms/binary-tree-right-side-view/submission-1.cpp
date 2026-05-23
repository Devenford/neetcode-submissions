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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;
        if(!root) {
            return values;
        }
        deque<TreeNode*> nodequeue = {root};

        while(!nodequeue.empty()) {
            int n = nodequeue.size();
            for(int i=0; i<n; i++) {
                TreeNode* curr = nodequeue.front();
                nodequeue.pop_front();
                
                if(curr->left) {
                    nodequeue.push_back(curr->left);
                }
                if(curr->right) {
                    nodequeue.push_back(curr->right);
                }
                if(i==(n-1)) {
                    values.push_back(curr->val);
                }
            }
        }

        return values;
    }
};
