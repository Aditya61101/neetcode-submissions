class MyStack {
    queue<int>q1,q2;
    int juggle(queue<int>&q1, queue<int>&q2) {
        while(q1.size()!=1) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        return top;
    }
public:
    MyStack() {}
    
    void push(int x) {
        if(!q1.size()) q2.push(x);
        else q1.push(x);
    }
    
    int pop() {
        int top = -1;
        if(q1.size()) top = juggle(q1,q2);
        else top = juggle(q2,q1);
        return top;
    }
    
    int top() {
        int top = -1;
        if(q2.size()) swap(q1,q2);
        top = juggle(q1,q2);
        q2.push(top);
        return top;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */