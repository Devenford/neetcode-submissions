// single-pass

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
        m[nullptr] = nullptr; // to prevent the mapping: m[nullptr] = 0 in the below code

        while(l1) {
            if (m.count(l1) == 0) {
                m[l1] = new Node(0);
            }
            m[l1]->val = l1->val;    // m[l1] = l2

            if (m.count(l1->next) == 0) {
                m[l1->next] = new Node(0);
            }
            m[l1]->next = m[l1->next];

            if (m.count(l1->random) == 0) {
                m[l1->random] = new Node(0);
            }
            m[l1]->random = m[l1->random];

            l1 = l1->next;
        }

        return m[head];
    }
};
