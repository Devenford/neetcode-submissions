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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if(root==nullptr) {
            return traversal;
        }
        deque<TreeNode*> nodequeue = {root};

        while(!nodequeue.empty()) {
            int n = nodequeue.size();
            vector<int> temp;

            for(int i=0; i<n; i++) {
                TreeNode *curr = nodequeue.front();
                temp.push_back(curr->val);
                nodequeue.pop_front();

                if(curr->left) {
                    nodequeue.push_back(curr->left);
                }
                if(curr->right) {
                    nodequeue.push_back(curr->right);
                }
            }
            
            traversal.push_back(temp);
        }

        return traversal;
    }
};
