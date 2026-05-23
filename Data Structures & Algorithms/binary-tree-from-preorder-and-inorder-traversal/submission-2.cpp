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
        if(preorder.empty()) {
            return nullptr;
        }
        if(preorder.size()==1) {
            TreeNode *leaf_node = new TreeNode(preorder[0]);
            return leaf_node;
        }

        int root_value = preorder[0], root_index = 0;
        while(inorder[root_index] != root_value) {
            root_index++;
        }
        
        vector<int> leftin(inorder.begin(), inorder.begin()+root_index);
        vector<int> leftpre(preorder.begin()+1, preorder.begin()+root_index+1);
        vector<int> rightin(inorder.begin()+root_index+1, inorder.end());
        vector<int> rightpre(preorder.begin()+root_index+1, preorder.end());

        TreeNode *root = new TreeNode(root_value);
        root->left = buildTree(leftpre, leftin);
        root->right = buildTree(rightpre, rightin);

        return root;
    }
};
