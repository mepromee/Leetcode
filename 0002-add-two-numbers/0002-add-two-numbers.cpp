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
        ListNode* cur1 = l1, *cur2 = l2, *ansHead = nullptr, *curNode = nullptr;
        bool isHead = true;
        int sum = 0, carry = 0, d1, d2;
        
        while(cur1 != nullptr || cur2 != nullptr) {
            if(cur1 == nullptr) d1 = 0;
            else {
                d1 = cur1->val;
                cur1 = cur1->next;
            }
            
            if(cur2 == nullptr) d2 = 0;
            else {
                d2 = cur2->val;
                cur2 = cur2->next;
            }
            
            sum = d1 + d2 + carry;
            ListNode *newNode = new ListNode(sum%10);
            if(isHead) {
                curNode = newNode;
                isHead = false;
                ansHead = curNode;
            }
            else {
                curNode->next = newNode;
                curNode = newNode;
            }
            
            carry = sum/10;
        }
        
        while(carry != 0) {
            ListNode *newNode = new ListNode(carry%10);
            curNode->next = newNode;
            curNode = newNode;
            carry = carry/10;
        }
        
        return ansHead;
    }
};
/*
microsoft
9:16
*/