class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        shiftFromPushStackToPopStack();
        
        int num = popStack.top();
        popStack.pop();
        return num;
    }
    
    int peek() {
        shiftFromPushStackToPopStack();
        return popStack.top();
    }
    
    bool empty() {
        return pushStack.size() == 0 && popStack.size() == 0;
    }
private:
    stack<int>pushStack, popStack;
    void shiftFromPushStackToPopStack() {
        if(popStack.empty())
        while(!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 
 /*
 9:34
 */
 