#include<climits>
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
    int dfs(TreeNode* node, int &maxPath) {
        if (!node) {
            return 0;
        }

        int Lpath = max(dfs(node->left, maxPath), 0); // don't pick the Lpath if the sum is negative
        int Rpath = max(dfs(node->right, maxPath), 0); // don't pick the Rpath if the sum is negative
        maxPath = max({maxPath, Lpath + Rpath + node->val});

        /* The initial calculation of:
        maxPath = max({maxPath, Lpath + Rpath + node->val, node->val, Lpath + node->val, Rpath + node->val});
        is simplified to maxPath = max({maxPath, Lpath + Rpath + node->val})

        Since (the pathSum = max(0, pathSum) condition accounts for all 3 cases below):
        if Lpath < 0, then Lpath = max(0, -ve) = 0 and Lpath + Rpath + node->val = Rpath + node->val
        if Rpath < 0, then Rpath = max(0, -ve) = 0 and Lpath + Rpath + node->val = Lpath + node->val
        if both Lpath < 0 and Rpath < 0, then Lpath = max(0, -ve) = 0, Rpath = max(0, -ve) = 0, and Lpath + Rpath + node->val = node->val
        */
        
        return node->val + max(Lpath, Rpath); // you can only choose one path/side, since you can't branch (A node cannot appear in the sequence more than once). A branch would cause revisiting nodes.
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};
