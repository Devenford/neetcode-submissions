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
    bool checkPath(TreeNode* root, int targetSum, int pathSum) {
        if(!root) {
            return false;
        }
        pathSum += root->val;

        if(!root->left && !root->right) {
            if (pathSum==targetSum) {
                return true;
            }
            else {
                return false;
            }
        }

        if(checkPath(root->left, targetSum, pathSum)) {
            return true;
        }
        if(checkPath(root->right, targetSum, pathSum)) {
            return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPath(root, targetSum, 0);
    }
};