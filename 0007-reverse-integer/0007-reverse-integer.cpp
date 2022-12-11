class Solution {
public:
    int reverse(int x) {
        int n = x, r = 0, d;
        while(n) {
            d = n%10;
            if(d < 0) d = -d;
            if(isIn32Bit(r, d, x>=0)) {
                r = r * 10 + d;
            }
            else {
                r = 0;
                break;
            }
            n/=10;
        }
        if(x < 0) r *= -1;
        return r;
    }
private:
    bool isIn32Bit(int cur, int d, bool isPos) {
        if(isPos || d == 0) return cur <= (INT_MAX - d) / 10;
        return cur <=  (INT_MAX - d + 1) / 10;
    }
};
/*
amazon
apple
adobe

r * 10 + d > int_max
r * 10 > im - d
r > im-d/10

r*10 + d = im + 1
r*10 = im-d+1

-123

r * 10 + d ) * -1 < intmin
r * 10 + d > -intmin
r * 10 > intmax+1 - d
r > intmax+1 - d / 10
*/