class MyQueue {
    stack<int>main, helper;
    int getAns() {
        // this condition ensures that every element is transferred at most 1 time.
        if(helper.empty()) {
            while(main.size()) {
                helper.push(main.top());
                main.pop();
            }
        }
        return helper.top();
    }
public:
    MyQueue() {}
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int front = getAns();
        helper.pop();
        return front;
    }
    
    int peek() {
        int front = getAns();
        return front;
    }
    
    bool empty() {
        return main.empty() && helper.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */