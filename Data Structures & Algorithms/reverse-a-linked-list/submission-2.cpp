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
ListNode *nextNode(ListNode *ptr, ListNode *prev) {
    if(!ptr) {
        return prev;
    }

    ListNode *next = ptr->next;
    ptr->next = prev;
    return nextNode(next, ptr);
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return nextNode(head, nullptr);
    }
};
