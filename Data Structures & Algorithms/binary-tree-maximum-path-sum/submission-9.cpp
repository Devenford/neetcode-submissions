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
        maxPath = max({maxPath, Lpath + Rpath + node->val, node->val, Lpath + node->val, Rpath + node->val});
        
        return max({node->val, Lpath + node->val, Rpath + node->val});
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};
