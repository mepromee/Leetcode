class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        bool isValidParenthese = true;
        
        for(auto &ch: s) {
            if(isOpenBracket(ch)) {
                stk.push(ch);
            }
            else if(hasMatchingClosedBracket(ch, stk)) {
                stk.pop();
            }
            else {
                isValidParenthese = false;
                break;
            }
        }
        
        if(stk.size() > 0) isValidParenthese = false;
        return isValidParenthese;
    }

    
private:
    bool isOpenBracket(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }
    
    bool hasMatchingClosedBracket(char ch, stack<char>&stk) {
        if(stk.size() == 0) return false;
        if(ch == ')') return stk.top() == '(';
        if(ch == '}') return stk.top() == '{';
        else return stk.top() == '[';
    }
};
/*
1:35
*/