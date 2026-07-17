#include <stack>
#include <vector>

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
class Solution {     // Iterative Version
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;
        std::stack<TreeNode*> stack;
        std::stack<bool> visit;  //Have both children been visited?
        stack.push(root);
        visit.push(false);

        while (stack.size()) {
            TreeNode* curr = stack.top();
            bool visited = visit.top();
            stack.pop();
            visit.pop();

            if (curr) {
                if (visited) {
                    sol.push_back(curr->val);
                } else {
                    stack.push(curr);
                    visit.push(true);
                    stack.push(curr->right);
                    visit.push(false);
                    stack.push(curr->left);
                    visit.push(false);
                }
            }
        }

        return sol;
    }
};