class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int iceCream = 0;
        
        for(auto cost: costs) {
            if(coins-cost >= 0) {
                coins -= cost;
                iceCream++;
            }
            else break;
        }
        
        return iceCream;
    }
};
/*
6:42
*/