class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> digitToStrMap = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
                
        for(auto &digit: digits) {
            strs.push_back(digitToStrMap[digit-'0']);
        }
        
        if(digits.size()==0) return ans;
        sz = strs.size();
        
        string tmp = "";
        for(int i = 0; i < 4; i++) {
            generateCombinationsOfLetters(tmp, 0,i);
        }
        return ans;
    }
private:
    vector<string> ans, strs;
    int sz;
    void generateCombinationsOfLetters(string& cur, int r, int c){
        if(r == sz || c == strs[r].size()) {
            return;
        }
        cur += strs[r][c];
        if(r+1 == sz) {
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        for(int i = 0; i < 4; i++) {
            generateCombinationsOfLetters(cur, r+1, i);
        }
        cur.pop_back();
    }
    
    
};
/*
3:23

"abc", 
"def", 
"ghi", 
"jkl"

j, k, l, gj, gk, gl, hj, hk, hl, ij, ik, il, 


*/