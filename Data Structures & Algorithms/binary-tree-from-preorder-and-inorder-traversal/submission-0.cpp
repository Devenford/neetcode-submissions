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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==1) {
            TreeNode *leaf_node = new TreeNode(preorder[0]);
            return leaf_node;
        }

        int root_value = preorder[0], root_index = 0;
        while(inorder[root_index] != root_value) {
            root_index++;
        };
        
        vector<int> leftin, rightin, leftpre, rightpre;
        for(int i=0; i<root_index; i++) {
            leftin.push_back(inorder[i]);
            leftpre.push_back(preorder[i+1]);
        }
        for(int i=root_index+1; i<preorder.size(); i++) {
            rightin.push_back(inorder[i]);
            rightpre.push_back(preorder[i]);
        }

        TreeNode *root = new TreeNode(root_value);
        if (!leftpre.empty()) {
            root->left = buildTree(leftpre, leftin);
        }
        if (!rightpre.empty()) {
            root->right = buildTree(rightpre, rightin);
        }

        return root;
    }
};
