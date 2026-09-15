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
    int preorder(TreeNode *node, int d) {
        if (node == nullptr) {
            return d;
        }

        return max(preorder(node->left, d+1), preorder(node->right, d+1));
    }

public:
    int maxDepth(TreeNode* root) {
        return preorder(root, 0);
    }
};
