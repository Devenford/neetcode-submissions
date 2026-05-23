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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2, *prev, *head;
        if(temp1==nullptr) {
            return temp2;
        }
        if(temp2==nullptr) {
            return temp1;
        }

        while(temp1!=nullptr && temp2!=nullptr) {
            if(temp1->val <= temp2->val) {
                if(temp1==list1 && temp2==list2) {
                    head = temp1;
                    prev = temp1;
                    temp1 = temp1->next;
                }
                else {
                    prev->next = temp1;
                    prev = temp1;
                    temp1 = temp1->next;
                }
            }
            else {
                if(temp1==list1 && temp2==list2) {
                    head = temp2;
                    prev = temp2;
                    temp2 = temp2->next;
                }
                else {
                    prev->next = temp2;
                    prev = temp2;
                    temp2 = temp2->next;
                }
            }
        }

        if (temp1==nullptr) {
            while(temp2!=nullptr) {
                prev->next = temp2;
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp2==nullptr) {
            while(temp1!=nullptr) {
                prev->next = temp1;
                prev = temp1;
                temp1 = temp1->next;
            }
        }

        return head; 
    }
};
