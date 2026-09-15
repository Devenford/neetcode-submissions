#include<bits/stdc++.h>
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
    int postorder(TreeNode *node, int d) {
        if (node == nullptr) {
            return d;
        }

        return max(postorder(node->left, d+1), postorder(node->right, d+1));
    }

public:
    int maxDepth(TreeNode* root) {
        return postorder(root, 0);
    }
};
