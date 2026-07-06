#include<algorithm>
#include<vector>
using namespace std;

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
        ListNode *slow = head, *fast = head;
        int halfSize = 0;
        vector<int> cache;

        while(fast != nullptr) {
            cache.push_back(slow->val);
            halfSize++;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow now points to the head of the second half of the list
        int maxSum = 0;
        for(int i=halfSize-1; i>=0; i--) {
            maxSum = max(maxSum, cache[i] + slow->val);
            slow = slow->next;
        }

        return maxSum;
    }
};