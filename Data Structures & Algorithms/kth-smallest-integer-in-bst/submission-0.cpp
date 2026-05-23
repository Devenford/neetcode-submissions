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
    int index = 0, value = -1;
    void inOrder(TreeNode* node, int k) {
        if (value!=-1) {
            return;
        }
        if (node==nullptr) {
            return;
        }
        
        inOrder(node->left, k);
        index++;
        if (index==k) {
            value = node->val;
            return;
        }
        inOrder(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return value;
    }
};
