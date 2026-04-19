class MyQueue {
    stack<int>main, helper;
public:
    MyQueue() {}
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        while(main.size()) {
            helper.push(main.top());
            main.pop();
        }
        int front = helper.top();
        helper.pop();
        while(helper.size()){
            main.push(helper.top());
            helper.pop();
        }
        return front;
    }
    
    int peek() {
        while(main.size()) {
            helper.push(main.top());
            main.pop();
        }
        int front = helper.top();
        while(helper.size()){
            main.push(helper.top());
            helper.pop();
        }
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