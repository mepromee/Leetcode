class Solution {
public:
    int myAtoi(string s) {
        long long int n = 0;
        int sign = 1;
        bool isStart = true;
        
        for(auto c: s) {
            if(c == ' ' && isStart) continue;
            else if((c == '+' || c == '-' ) && isStart) {
                isStart = false;
                if(c == '-')
                    sign = -1;
            }
            else if(c >= '0' && c <= '9') {
               isStart = false;
                n = n*10 + c-'0';
                if(!isIn32Bit(n*sign)) {
                    if(sign == -1) n = INT_MIN * -1ll;
                    else n = INT_MAX;
                    break;
                }
            }
            else break;
        }
        
        return n * sign;
    }
private:
    bool isIn32Bit(long long int n) {
        return n >= INT_MIN && n <= INT_MAX;
    }
};
/*
9:36

microsoft
amazon
*/