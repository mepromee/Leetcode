class Solution {
public:
    int reverse(int x) {
        long long int n = x;
        long long int res = 0;
        if(n < 0) n = -n;
        while(n) {
            res *= 10;
            res += n%10;
            if(!isIn32Bit(res)) {
                res = 0;
                break;
            }
            n/=10;
        }
        
        if(x < 0) return res * -1;
        return res;
    }
private:
    bool isIn32Bit(long long int x) {
        return x >= INT_MIN && x <= INT_MAX;
    }
};
/*
amazon
apple
adobe
*/