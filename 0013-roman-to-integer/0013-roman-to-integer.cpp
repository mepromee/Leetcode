class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> subtract_map = {{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        
        unordered_map<string,int> num_map = {{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};
        
        
        int i = 0, ans = 0;
        
        while(i < s.length()) {
            if(i+1 < s.length() && subtract_map.find(string()+s[i]+s[i+1]) != subtract_map.end()) {
                ans += subtract_map[string()+s[i]+s[i+1]];
                i+=2;
            }
            else {
                ans += num_map[string()+s[i]];
                i++;
            }
        }
    
        return ans;
    }
};
/*
1:14
*/