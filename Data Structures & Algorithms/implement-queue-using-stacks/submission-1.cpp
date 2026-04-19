class MyQueue {
    stack<int>main, helper;
    void helperToMain() {
        while(helper.size()){
            main.push(helper.top());
            helper.pop();
        }
    }
    int mainToHelper() {
        while(main.size()) {
            helper.push(main.top());
            main.pop();
        }
        int front = helper.top();
        return front;
    }
public:
    MyQueue() {}
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int front = mainToHelper();
        helper.pop();
        helperToMain();
        return front;
    }
    
    int peek() {
        int front = mainToHelper();
        helperToMain();
        return front;
    }
    
    bool empty() {
        return main.empty();
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