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
    int dfs(TreeNode *node, int largest) { // preorder
        if (!node) {
            return 0;
        }
        
        int count = node->val >= largest ? 1 : 0;
        largest = max(largest, node->val);
        count += dfs(node->left, largest);
        count += dfs(node->right, largest);
        return count;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
