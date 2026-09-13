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
        if (!head) {
            return nullptr;
        }
        
        Node *h = new Node(head->val); // new head
        Node *l1 = head;
        Node *l2 = h;
        unordered_map<Node*, Node*> m; // <node address in original list,  node address in new list>
        // it maps each original node to the copied node
        m[head] = h;

        while(l1->next) {
            l1 = l1->next;
            Node *temp = new Node(l1->val);
            l2->next = temp;
            l2 = l2->next;
            m[l1] = l2;
        }

        l1 = head;
        l2 = h;
        while(l1) {
            l2->random = m[l1->random];
            l1 = l1->next;
            l2 = l2->next;
        }

        return h;
    }
};
