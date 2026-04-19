// in this case juggling happens during write, so its perfect for read heavy.
class MyStack {
    queue<int>q;
    void juggle(queue<int>&out, queue<int>&in) {
        while(out.size()) {
            in.push(out.front());
            out.pop();
        }
    }
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int sz=q.size();
        while(sz>1) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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