class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nxtBuy = 0, nxtSell = 0, nxtNxtBuy = 0, curBuy, curSell;
            
        for(int i = n-1; i >=0; i--) {
            
            curBuy = max(nxtBuy, nxtSell - prices[i]);
            curSell = max(nxtSell, nxtNxtBuy + prices[i]);
            
            nxtNxtBuy = nxtBuy;
            nxtBuy = curBuy;
            nxtSell = curSell;
        }
        
        return curBuy;
    }
};
/*
8:15

 n-2 n-1 n
*/