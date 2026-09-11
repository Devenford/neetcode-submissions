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
    void reorderList(ListNode* head) {
        ListNode *fast = head->next, *slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // now, slow = last node in set1, fast = last node in set2 or nullptr

        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr; // disconnect the two sets
        while(curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // now, prev = last element = first element of reversed subset

        ListNode *temp1 = head, *temp2 = prev;
        while(temp2) {
            ListNode *temp = temp1->next;
            temp1->next = temp2;
            temp1 = temp;
            temp = temp2->next;
            temp2->next = temp1;
            temp2 = temp;
        }
    }
};
