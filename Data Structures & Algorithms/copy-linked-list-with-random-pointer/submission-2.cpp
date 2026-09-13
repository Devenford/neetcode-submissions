#include<unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *l1 = head;
        unordered_map<Node*, Node*> m; // <node address in original list,  node address in new list>
        // it maps each original node to the copied node

        while(l1) {
            Node *copy = new Node(l1->val);
            m[l1] = copy;
            l1 = l1->next;
        }

        l1 = head;
        while(l1) {
            Node *l2 = m[l1];
            l2->next = m[l1->next];
            l2->random = m[l1->random];
            l1 = l1->next;
        }

        return m[head];
    }
};
