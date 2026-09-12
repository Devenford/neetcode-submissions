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
    int dfs(ListNode *prev, ListNode *curr, ListNode *&head, int n) {
        if (!curr) { // curr == nullptr
            return 0;
        }

        int index = 1 + dfs(curr, curr->next, head, n);
        if (index == n) {
            if (prev) { // prev != nullptr
                prev->next = curr->next;
            }
            else { // prev = nullptr (i.e., the first node is deleted)
                head = curr->next;
            }
            delete curr;
        }
        return index;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        dfs(nullptr, head, head, n);
        return head;
    }
};
