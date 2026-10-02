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
    void dfs(TreeNode *node, int largest, int &count) { // preorder
        if (!node) {
            return;
        }
        
        if (node->val >= largest) {
            count++;
            largest = node->val;
        }

        dfs(node->left, largest, count);
        dfs(node->right, largest, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }
};
