// in this case juggling happens during read, so its perfect for write heavy.
class MyStack {
    queue<int>q1,q2;
    void juggle(queue<int>&out, queue<int>&in) {
        while(out.size()) {
            in.push(out.front());
            out.pop();
        }
    }
public:
    MyStack() {}
    
    void push(int x) {
        if(q1.empty()) {q1.push(x); juggle(q2,q1);}
        else {q2.push(x); juggle(q1,q2);}
    }
    
    int pop() {
        int top;
        if(q1.size()) {
            top = q1.front();
            q1.pop();
            return top;
        }
        top = q2.front();
        q2.pop();
        return top;
    }
    
    int top() {
        if(q2.size()) return q2.front();
        return q1.front();
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