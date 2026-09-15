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
    int postorder(TreeNode *node, int &diameter) { // d = depth
        if (!node) {
            return 0;
        }

        // left and right heights
        int leftH = postorder(node->left, diameter);
        int rightH = postorder(node->right, diameter);
        // The diameter of a binary tree is the maximum sum of the heights of the left and right subtrees, for every node in the tree
        diameter = max(diameter, leftH + rightH);
        return 1 + max(leftH, rightH);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        postorder(root, diameter);
        return diameter;
    }
};
