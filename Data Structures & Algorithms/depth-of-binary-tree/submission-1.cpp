// bfs approach
#include<queue>
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
    int maxDepth(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        if (root) { // root != nullptr
            q.push(root);
        }

        // level-by-level traversal
        while(!q.empty()) {
            int qlength = q.size();
            for(int i=0; i<qlength; i++) {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            level++;
        }

        return level;
    }
};
