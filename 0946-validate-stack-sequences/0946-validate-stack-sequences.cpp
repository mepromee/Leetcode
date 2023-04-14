class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, j = 0;
        while(i < popped.size()) {
            if(!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
            else if(j < pushed.size()){
                stk.push(pushed[j]);
                j++;
            }
            else break;
        }
        
        return i == popped.size();
    }
};
/*
1:29
*/