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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int carry = 0; // carry

        while(l1 || l2 || carry) {
            int d1 = l1 == nullptr ? 0 : l1->val;
            int d2 = l2 == nullptr ? 0 : l2->val;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = temp;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }

        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
