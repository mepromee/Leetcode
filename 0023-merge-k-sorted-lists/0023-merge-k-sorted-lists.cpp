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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minValId = -1, curMin = INT_MAX;
        ListNode *head, *cur;
        head = cur = new ListNode(-1);
        
        while(true){
            minValId = -1;
            curMin = INT_MAX;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != nullptr) {
                    if(curMin > lists[i]->val) {
                        curMin = lists[i]->val;
                        minValId = i;
                    }
                }
            }
            
            if(minValId == -1) break;
            cur->next = lists[minValId];
            cur = cur->next;
            lists[minValId] = lists[minValId]->next;
        }
        return head->next;
    }
};
/*
2:19
*/