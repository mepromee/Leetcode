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
        priority_queue<pair<int,ListNode*>>pq;
        ListNode *head, *cur;
        head = cur = new ListNode(-1);
        
        for(auto list: lists) {
            if(list != nullptr) 
                pq.push({-list->val, list});
        }
        while(!pq.empty()) {
            ListNode *topNode = pq.top().second;
            
            cur->next = topNode;
            cur = cur->next;
            
            pq.pop();
            if(topNode->next != nullptr) {
                pq.push({-topNode->next->val, topNode->next});
            }
            
        }
        
        return head->next;
    }
};
/*
2:19
*/