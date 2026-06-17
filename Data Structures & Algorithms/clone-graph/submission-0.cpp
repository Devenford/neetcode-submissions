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
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        queue<Node*> q;
        unordered_map<Node*, Node*> oldToNew; //mapping btw. old (original) and new (clone) graph nodes
        q.push(node);
        oldToNew[node] = new Node(node->val);

        while(q.size()) {
            Node *curr = q.front();
            q.pop();

            for (Node *neighbor : curr->neighbors) {
                if (oldToNew.count(neighbor)==0) {
                    q.push(neighbor);
                    oldToNew[neighbor] = new Node(neighbor->val);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return oldToNew[node];
    }
};
