class Solution {
public:
    string simplifyPath(string path) {
        string canonicalPath = "";
        vector<string> vec;
        stack<string> stk;
        string dirName;
        
        stk.push("/");
        
        for(int i = 0 ; i < path.size(); i++) {
            if(path[i] == '/') {
                if(stk.empty() || stk.top() != "/") stk.push("/");
            }
            else {
                dirName = "";
                while(i < path.size() && path[i] != '/') {
                    dirName += path[i];
                    i++;
                }
                i--;
                if(dirName == ".") continue;
                else if(dirName == "..") {
                    if(!stk.empty()) stk.pop();
                    if(!stk.empty()) stk.pop();
                }
                else {
                    stk.push(dirName);
                }
            }
        }
        
        if(stk.empty()) stk.push("/");
        else if(stk.size() > 1 && stk.top() == "/") stk.pop();
        
        while(!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }
        
        for(int i = vec.size()-1; i >= 0; i--) {
            canonicalPath += vec[i];
        }
        
        return canonicalPath;
        
    }
};
/*
1:18

/
.
*

abc../asd/.
ab/././b
////h.../../../../


/ 
*/