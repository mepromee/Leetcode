
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string mins = s;
            string tmp;
            int n = s.length();
            for(int i = 0; i < n; i++) {
                tmp = s.substr(i,n);
                if(tmp < mins) mins = tmp;
                s += s[i];
            }
            return mins;
        }
        else {
            sort(s.begin(),s.end());
            return s;
        }
    }
};
/*
iebfbyzadwxze

baaca
bacaa
bcaaa
caaab
aaabc
k k+1 k+2 .. k+k

k+k


....x.....y....z.............

*/