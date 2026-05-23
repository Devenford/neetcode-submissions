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
    int postOrder(TreeNode* root, bool &flag) {
        if (root==nullptr) {
            return 0;
        }

        //left and right subtree heights
        int lheight = postOrder(root->left, flag);
        int rheight = postOrder(root->right, flag);

        int balanceFactor = lheight - rheight;
        if (balanceFactor < -1 || balanceFactor > 1) {
            flag = false;
        }

        return lheight > rheight ? lheight + 1 : rheight + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        postOrder(root, flag);
        return flag;
    }
};
