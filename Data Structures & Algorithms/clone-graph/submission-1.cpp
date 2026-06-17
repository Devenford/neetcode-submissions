#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*> &oldToNew) {
        if (!node) {   // node==nullptr
            return nullptr;
        }
        if(oldToNew.count(node)) {  //node already created
            return oldToNew[node];
        }
        
        Node *copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node *neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, oldToNew));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }
};
