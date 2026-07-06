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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr, *next = nullptr;
        while(fast != nullptr) { // reverse the first half of the list
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // now prev points to the end of the first half of the list
        // traverse the first half backwards and the second half forwards
        int maxSum = 0;
        while (slow != nullptr) {
            maxSum = max(maxSum, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return maxSum;
    }
};