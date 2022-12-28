class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int cur, rem = 0, tot = 0;
        
        for(auto pile: piles) {
            pq.push(pile);
            tot += pile;
        }
        while(!pq.empty() && k--) {
            cur = pq.top();
            pq.pop();
            rem += cur/2;
            pq.push(cur - (cur/2));
        }
        
        return tot - rem;
    }
};
/*
5:48


10 5
5 2


*/