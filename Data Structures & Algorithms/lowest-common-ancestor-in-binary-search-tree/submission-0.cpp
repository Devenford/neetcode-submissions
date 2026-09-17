#include<algorithm>
using namespace std;

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = min(p->val, q->val), high = max(p->val, q->val);
        if (root->val >= low && root->val <= high) {
            return root;
        }

        if (root->val < low) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};
