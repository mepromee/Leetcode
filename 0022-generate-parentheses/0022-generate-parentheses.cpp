class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string parenthesis(n+n, '(');
        
        buildParenthesis(0, n+n, parenthesis);
        
        return parenthesisList;
    }
    
private:
    vector<string> parenthesisList;
    
    void buildParenthesis(int i, int n, string &parenthesis) {
        if(i == n) {
            if(isValidParenthesis(parenthesis)) {
                parenthesisList.push_back(parenthesis);
            }
            
            return;
        }
        
        parenthesis[i] = '(';
        buildParenthesis(i+1, n, parenthesis);
        
        parenthesis[i] = ')';
        buildParenthesis(i+1, n, parenthesis);
        
        return;
    }
    
    bool isValidParenthesis(string &parenthesis) {
        int openCount = 0;
        
        for(auto &bracket: parenthesis) {
            if(bracket == '(') openCount++;
            else if(openCount == 0) return false;
            else openCount--;
        }
        
        return openCount == 0;
    }
};
/*
1:46
M

000
*/