#include<string>
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

class Codec {
    void encode(TreeNode *node, string &output) { // preorder traversal
        if (!node) {
            output.append("N,"); // N = nullptr
            return;
        }
        
        output.append(to_string(node->val) + ',');

        encode(node->left, output);
        encode(node->right, output);
    }

    TreeNode* decode(string &data, int &i) { // preorder traversal
        if (data[i] == 'N') {
            i++;
            return nullptr;
        }

        string temp;
        while(data[i] != ',') {
            temp.push_back(data[i]);
            i++;
        }

        TreeNode *node = new TreeNode(stoi(temp));
        node->left = decode(data, ++i);
        node->right = decode(data, ++i);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        encode(root, output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return decode(data, index);
    }
};
