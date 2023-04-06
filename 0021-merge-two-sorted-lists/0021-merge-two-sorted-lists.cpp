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
        ListNode *sortedListHead = nullptr;
        ListNode *cur;
        int curMin;
        
        while(list1 != nullptr || list2 != nullptr) {
            if(list1 == nullptr || (list2 != nullptr && list2->val <= list1->val)) {
                curMin = list2->val;
                list2 = list2->next;
            }
            else {
                curMin = list1->val;
                list1 = list1->next;
            }
            
            ListNode *newNode = new ListNode(curMin);
            if(sortedListHead == nullptr) {
                cur = sortedListHead = newNode;
            }
            else {
                cur->next = newNode;
                cur = cur->next;
            }
        }
        
        return sortedListHead;
        
    }
};
/*
1:51
*/