// Two pointers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *L = dummy, *R = head;
        for(int i=1; i-1 < n; i++) {
            R = R->next;
        }

        while(R) {
            R = R->next;
            L = L->next;
        }
        // L now points to one before the node to be removed
        L->next = L->next->next;
        return dummy->next;
    }
};
