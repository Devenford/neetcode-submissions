#include<algorithm>
#include<climits>
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
    int dfs(TreeNode* root, int &maxPath) {
        if (!root) {
            return 0;
        }
    
        int Lpath = dfs(root->left, maxPath);
        int Rpath = dfs(root->right, maxPath);

        maxPath = max({maxPath, Lpath + root->val, Rpath + root->val, Lpath + Rpath + root->val, root->val});
        return max({Lpath + root->val, Rpath + root->val, root->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};
 