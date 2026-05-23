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
    ListNode* merge(ListNode* list1, ListNode *list2) {
        ListNode node;
        ListNode *temp = &node;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }
        
        return node.next;
    }

    ListNode* mergeSort(vector<ListNode*> &arr, int s, int e) {
        if(s==e) {
            return arr[s];
        }

        int m = (s+e)/2;
        ListNode *left = mergeSort(arr, s, m);
        ListNode *right = mergeSort(arr, m+1, e);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if(lists.empty()) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size()-1);
    }
};
