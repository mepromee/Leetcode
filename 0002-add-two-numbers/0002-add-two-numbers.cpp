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
        ListNode *dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int d1,d2,sum,carry=0;
        
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            d1 = l1 == nullptr ? 0 : l1->val;
            d2 = l2 == nullptr ? 0 : l2->val;
            sum = d1 + d2 + carry;
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = newNode;
            
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }
        
        return dummyHead->next;
    }
};
/*
microsoft
9:16
*/