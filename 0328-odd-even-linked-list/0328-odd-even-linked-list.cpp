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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* lastOdd = head, *lastEven = head->next;
        int pos = 2;
        ListNode* cur = head->next;
        while(cur != nullptr) {
            cur = cur->next;
            pos++;
            if(pos%2 && cur != nullptr) {
                //odd
                ListNode* lastOddNxtTmp = lastOdd->next;
                ListNode* curNxtTmp = cur->next;
                
                lastOdd->next = cur;
                cur->next = lastOddNxtTmp;
                
                lastEven->next = curNxtTmp;
                
                lastOdd = cur;
                
                cur = lastEven;
            }
            else {
                //even
                lastEven = cur;
            }
        }
        
        return head;
    }
};
/*
5:22

1 2 3 4 5 6 7 8 9 10

1 3 5 2 4 6 
*/